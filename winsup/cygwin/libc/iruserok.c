/* Based on the rcmd.c.new file distributed with linux libc 5.4.19
   Adapted to inetutils by Bernhard Rosenkraenzer <bero@startrek.in-trier.de>

   Note that a lot in this file is superfluous; hopefully it won't be a
   problem for systems that need it for iruserok &c....  */
/*
 * Copyright (c) 1983, 1993, 1994
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "winsup.h"
#include <pwd.h>
#include <sys/stat.h>
#include <malloc.h>
#include <string.h>
#include <netdb.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

#ifndef PATH_HEQUIV
# define PATH_HEQUIV "/etc/hosts.equiv"
#endif

int         __check_rhosts_file = 1;
const char *__rcmd_errstr;

/*
 * Returns "true" if match, 0 if no match.
 */
static int
__icheckhost(raddr, lhost)
  u_long raddr;
  register char *lhost;
{
	register struct hostent *hp;
	register u_long laddr;
	register char **pp;

	/* Try for raw ip address first. */
	if (isdigit(*lhost) && (long)(laddr = cygwin_inet_addr(lhost)) != -1)
		return (raddr == laddr);

	/* Better be a hostname. */
	if ((hp = cygwin_gethostbyname(lhost)) == NULL)
		return (0);

	/* Spin through ip addresses. */
	for (pp = hp->h_addr_list; *pp; ++pp)
		if (!bcmp(&raddr, *pp, sizeof(u_long)))
			return (1);

	/* No match. */
	return (0);
}

/*
 * XXX
 * Don't make static, used by lpd(8).
 *
 * Returns 0 if ok, -1 if not ok.
 */
static int
__ivaliduser(hostf, raddr, luser, ruser)
  struct __sFILE64 *hostf;
  u_long raddr;
  const char *luser;
  const char *ruser;
{
	size_t buf_offs = 0;
	size_t buf_len = 256;
	char *buf = malloc (buf_len);

	if (! buf)
		return -1;

	while (fgets(buf + buf_offs, buf_len - buf_offs, hostf)) {
		/*int ch;*/
		register char *user, *p;

		if (strchr(buf + buf_offs, '\n') == NULL) {
			/* No newline yet, read some more.  */
			buf_offs += strlen (buf + buf_offs);

			if (buf_offs >= buf_len - 1) {
				/* Make more room in BUF.  */
				char *new_buf;

				buf_len += buf_len;
				new_buf = realloc (buf, buf_len);

				if (! new_buf) {
					free (buf);
					return -1;
				}

				buf = new_buf;
			}

			continue;
		}

		buf_offs = 0;			/* Start at beginning next time around.  */

		p = buf;
		while (*p != '\n' && *p != ' ' && *p != '\t' && *p != '\0') {
			/* *p = isupper(*p) ? tolower(*p) : *p;  -- Uli */
			*p = tolower(*p);	/* works for linux libc */
			p++;
		}
		if (*p == ' ' || *p == '\t') {
			*p++ = '\0';
			while (*p == ' ' || *p == '\t')
				p++;
			user = p;
			while (*p != '\n' && *p != ' ' &&
			    *p != '\t' && *p != '\0')
				p++;
		} else
			user = p;
		*p = '\0';

		if (__icheckhost(raddr, buf) && !strcmp(ruser, *user ? user : luser)) {
			free (buf);
			return (0);
		}
	}

	free (buf);

	return (-1);
}

/*
 * New .rhosts strategy: We are passed an ip address. We spin through
 * hosts.equiv and .rhosts looking for a match. When the .rhosts only
 * has ip addresses, we don't have to trust a nameserver.  When it
 * contains hostnames, we spin through the list of addresses the nameserver
 * gives us and look for a match.
 *
 * Returns 0 if ok, -1 if not ok.
 */
int
iruserok(raddr, superuser, ruser, luser)
  u_long raddr;
  int superuser;
  const char *ruser;
  const char *luser;
{
	register const char *cp;
	struct __stat64 sbuf;
	struct passwd *pwd;
	struct __sFILE64 *hostf;

	uid_t uid;
	int first = 1;
	char *pbuf;

	first = 1;
	hostf = superuser ? NULL : fopen64(PATH_HEQUIV, "rt");
again:
	if (hostf) {
		if (__ivaliduser(hostf, raddr, luser, ruser) == 0) {
			(void) fclose(hostf);
			return(0);
		}
		(void) fclose(hostf);
	}
	if (first == 1 && (__check_rhosts_file || superuser)) {
		first = 0;
		if ((pwd = getpwnam(luser)) == NULL)
			return(-1);

		pbuf = malloc (strlen (pwd->pw_dir) + sizeof "/.rhosts");
		if (! pbuf)
		  {
		    errno = ENOMEM;
		    return -1;
		  }
		strcpy (pbuf, pwd->pw_dir);
		strcat (pbuf, "/.rhosts");

		/*
		 * Change effective uid while opening .rhosts.  If root and
		 * reading an NFS mounted file system, can't read files that
		 * are protected read/write owner only.
		 */
		uid = geteuid32();
		(void)seteuid32(pwd->pw_uid);
		hostf = fopen64(pbuf, "rt");
		(void)seteuid32(uid);

		if (hostf == NULL)
			return(-1);
		/*
		 * If not a regular file, or is owned by someone other than
		 * user or root or if writeable by anyone but the owner, quit.
		 */
		cp = NULL;
		if (lstat64(pbuf, &sbuf) < 0)
			cp = ".rhosts not regular file";
		else if (!S_ISREG(sbuf.st_mode))
			cp = ".rhosts not regular file";
		else if (fstat64(fileno(hostf), &sbuf) < 0)
			cp = ".rhosts fstat failed";
		else if (sbuf.st_uid && sbuf.st_uid != pwd->pw_uid)
			cp = "bad .rhosts owner";
		else if (sbuf.st_mode & (S_IWGRP|S_IWOTH))
			cp = ".rhosts writeable by other than owner";
		/* If there were any problems, quit. */
		if (cp) {
			__rcmd_errstr = (char *) cp;
			fclose(hostf);
			return(-1);
		}
		goto again;
	}
	return (-1);
}

int
ruserok(rhost, superuser, ruser, luser)
  const char *rhost;
  int superuser;
  const char *ruser;
  const char *luser;
{
	struct hostent *hp;
	u_long addr;
	char **ap;

	if ((hp = cygwin_gethostbyname(rhost)) == NULL)
		return (-1);
	for (ap = hp->h_addr_list; *ap; ++ap) {
		bcopy(*ap, &addr, sizeof(addr));
		if (iruserok(addr, superuser, ruser, luser) == 0)
			return (0);
	}
	return (-1);
}
