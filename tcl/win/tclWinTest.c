/* 
 * tclWinTest.c --
 *
 *	Contains commands for platform specific tests on Windows.
 *
 * Copyright (c) 1996 Sun Microsystems, Inc.
 *
 * See the file "license.terms" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * RCS: @(#) $Id$
 */

#define USE_COMPAT_CONST
#include "tclWinInt.h"

/*
 * Forward declarations of procedures defined later in this file:
 */
int		TclplatformtestInit _ANSI_ARGS_((Tcl_Interp *interp));
static int	TesteventloopCmd _ANSI_ARGS_((ClientData dummy,
	Tcl_Interp *interp, int argc, char **argv));
static int	TestvolumetypeCmd _ANSI_ARGS_((ClientData dummy,
	Tcl_Interp *interp, int objc,
	Tcl_Obj *CONST objv[]));
static int      TestwinclockCmd _ANSI_ARGS_(( ClientData dummy,
					      Tcl_Interp* interp,
					      int objc,
					      Tcl_Obj *CONST objv[] ));

/*
 *----------------------------------------------------------------------
 *
 * TclplatformtestInit --
 *
 *	Defines commands that test platform specific functionality for
 *	Unix platforms.
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	Defines new commands.
 *
 *----------------------------------------------------------------------
 */

int
TclplatformtestInit(interp)
    Tcl_Interp *interp;		/* Interpreter to add commands to. */
{
    /*
     * Add commands for platform specific tests for Windows here.
     */

    Tcl_CreateCommand(interp, "testeventloop", TesteventloopCmd,
            (ClientData) 0, (Tcl_CmdDeleteProc *) NULL);
    Tcl_CreateObjCommand(interp, "testvolumetype", TestvolumetypeCmd,
            (ClientData) 0, (Tcl_CmdDeleteProc *) NULL);
    Tcl_CreateObjCommand(interp, "testwinclock", TestwinclockCmd,
            (ClientData) 0, (Tcl_CmdDeleteProc *) NULL);
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * TesteventloopCmd --
 *
 *	This procedure implements the "testeventloop" command. It is
 *	used to test the Tcl notifier from an "external" event loop
 *	(i.e. not Tcl_DoOneEvent()).
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

static int
TesteventloopCmd(clientData, interp, argc, argv)
    ClientData clientData;		/* Not used. */
    Tcl_Interp *interp;			/* Current interpreter. */
    int argc;				/* Number of arguments. */
    char **argv;			/* Argument strings. */
{
    static int *framePtr = NULL; /* Pointer to integer on stack frame of
				  * innermost invocation of the "wait"
				  * subcommand. */

   if (argc < 2) {
	Tcl_AppendResult(interp, "wrong # arguments: should be \"", argv[0],
                " option ... \"", (char *) NULL);
        return TCL_ERROR;
    }
    if (strcmp(argv[1], "done") == 0) {
	*framePtr = 1;
    } else if (strcmp(argv[1], "wait") == 0) {
	int *oldFramePtr;
	int done;
	MSG msg;
	int oldMode = Tcl_SetServiceMode(TCL_SERVICE_ALL);

	/*
	 * Save the old stack frame pointer and set up the current frame.
	 */

	oldFramePtr = framePtr;
	framePtr = &done;

	/*
	 * Enter a standard Windows event loop until the flag changes.
	 * Note that we do not explicitly call Tcl_ServiceEvent().
	 */

	done = 0;
	while (!done) {
	    if (!GetMessage(&msg, NULL, 0, 0)) {
		/*
		 * The application is exiting, so repost the quit message
		 * and start unwinding.
		 */

		PostQuitMessage(msg.wParam);
		break;
	    }
	    TranslateMessage(&msg);
	    DispatchMessage(&msg);
	}
	(void) Tcl_SetServiceMode(oldMode);
	framePtr = oldFramePtr;
    } else {
	Tcl_AppendResult(interp, "bad option \"", argv[1],
		"\": must be done or wait", (char *) NULL);
	return TCL_ERROR;
    }
    return TCL_OK;
}

/*
 *----------------------------------------------------------------------
 *
 * Testvolumetype --
 *
 *	This procedure implements the "testvolumetype" command. It is
 *	used to check the volume type (FAT, NTFS) of a volume.
 *
 * Results:
 *	A standard Tcl result.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

static int
TestvolumetypeCmd(clientData, interp, objc, objv)
    ClientData clientData;		/* Not used. */
    Tcl_Interp *interp;			/* Current interpreter. */
    int objc;				/* Number of arguments. */
    Tcl_Obj *CONST objv[];		/* Argument objects. */
{
#define VOL_BUF_SIZE 32
    int found;
    char volType[VOL_BUF_SIZE];
    char *path;

    if (objc > 2) {
	Tcl_WrongNumArgs(interp, 1, objv, "?name?");
        return TCL_ERROR;
    }
    if (objc == 2) {
	/*
	 * path has to be really a proper volume, but we don't
	 * get query APIs for that until NT5
	 */
	path = Tcl_GetString(objv[1]);
    } else {
	path = NULL;
    }
    found = GetVolumeInformationA(path, NULL, 0, NULL, NULL, 
	    NULL, volType, VOL_BUF_SIZE);

    if (found == 0) {
	Tcl_AppendResult(interp, "could not get volume type for \"",
		(path?path:""), "\"", (char *) NULL);
	TclWinConvertError(GetLastError());
	return TCL_ERROR;
    }
    Tcl_SetResult(interp, volType, TCL_VOLATILE);
    return TCL_OK;
#undef VOL_BUF_SIZE
}

/*
 *----------------------------------------------------------------------
 *
 * TestclockCmd --
 *
 *	Command that returns the seconds and microseconds portions of
 *	the system clock and of the Tcl clock so that they can be
 *	compared to validate that the Tcl clock is staying in sync.
 *
 * Usage:
 *	testclock
 *
 * Parameters:
 *	None.
 *
 * Results:
 *	Returns a standard Tcl result comprising a four-element list:
 *	the seconds and microseconds portions of the system clock,
 *	and the seconds and microseconds portions of the Tcl clock.
 *
 * Side effects:
 *	None.
 *
 *----------------------------------------------------------------------
 */

static int
TestwinclockCmd( ClientData dummy,
				/* Unused */
		 Tcl_Interp* interp,
				/* Tcl interpreter */
		 int objc,
				/* Argument count */
		 Tcl_Obj *CONST objv[] )
				/* Argument vector */
{
    CONST static FILETIME posixEpoch = { 0xD53E8000, 0x019DB1DE };
				/* The Posix epoch, expressed as a
				 * Windows FILETIME */
    Tcl_Time tclTime;		/* Tcl clock */
    FILETIME sysTime;		/* System clock */
    Tcl_Obj* result;		/* Result of the command */
    LARGE_INTEGER t1, t2;

    if ( objc != 1 ) {
	Tcl_WrongNumArgs( interp, 1, objv, "" );
	return TCL_ERROR;
    }

    Tcl_GetTime( &tclTime );
    GetSystemTimeAsFileTime( &sysTime );
    t1.LowPart = posixEpoch.dwLowDateTime;
    t1.HighPart = posixEpoch.dwHighDateTime;
    t2.LowPart = sysTime.dwLowDateTime;
    t2.HighPart = sysTime.dwHighDateTime;
    t2.QuadPart -= t1.QuadPart;

    result = Tcl_NewObj();
    Tcl_ListObjAppendElement
	( interp, result, Tcl_NewIntObj( (int) (t2.QuadPart / 10000000 ) ) );
    Tcl_ListObjAppendElement
	( interp, result,
	  Tcl_NewIntObj( (int) ( (t2.QuadPart / 10 ) % 1000000 ) ) );
    Tcl_ListObjAppendElement( interp, result, Tcl_NewIntObj( tclTime.sec ) );
    Tcl_ListObjAppendElement( interp, result, Tcl_NewIntObj( tclTime.usec ) );

    Tcl_SetObjResult( interp, result );

    return TCL_OK;
}
