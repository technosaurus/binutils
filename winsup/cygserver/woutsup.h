/* woutsup.h: for Cygwin code compiled outside the DLL (i.e. cygserver).

   Copyright 2002, 2003 Red Hat, Inc.

This file is part of Cygwin.

This software is a copyrighted work licensed under the terms of the
Cygwin license.  Please consult the file "CYGWIN_LICENSE" for
details. */

#define _MT_SAFE 1

#ifdef __INSIDE_CYGWIN__
#error "woutsup.h is not for code being compiled inside the dll"
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#if _WIN32_WINNT < 0x0500
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#define WIN32_LEAN_AND_MEAN 1
#define _WINGDI_H
#define _WINUSER_H
#define _WINNLS_H
#define _WINVER_H
#define _WINNETWK_H
#define _WINSVC_H
#include <windows.h>
#include <wincrypt.h>
#include <lmcons.h>
#undef _WINGDI_H
#undef _WINUSER_H
#undef _WINNLS_H
#undef _WINVER_H
#undef _WINNETWK_H
#undef _WINSVC_H

#include "wincap.h"

#include "bsd_helper.h"
#include "bsd_log.h"
#include "bsd_mutex.h"

/* The one function we use from winuser.h most of the time */
extern "C" DWORD WINAPI GetLastError (void);

extern int cygserver_running;

#define SIGHANDLE(SIG)							\
  do									\
    {									\
      struct sigaction act;						\
									\
      act.sa_handler = &handle_signal;					\
      act.sa_mask = 0;							\
      act.sa_flags = 0;							\
									\
      if (sigaction (SIG, &act, NULL) == -1)				\
	{								\
	  panic ("failed to install handler for " #SIG ": %s",		\
		 strerror (errno));					\
	  exit (1);							\
	}								\
    } while (false)

#define debug_printf(f,...)	debug((f),##__VA_ARGS__)
#define syscall_printf(f,...)	log(LOG_ERR,(f),##__VA_ARGS__)
#define system_printf(f,...)	log(LOG_ERR,(f),##__VA_ARGS__)
