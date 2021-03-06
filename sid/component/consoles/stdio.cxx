// stdio.cxx - A simple console that uses standard I/O for
// enunciation.  -*- C++ -*-

// Copyright (C) 1999, 2000, 2003 Red Hat.
// This file is part of SID and is licensed under the GPL.
// See the file COPYING.SID for conditions for redistribution.

#include "config.h"
#include "components.h"

namespace console_stuff
{

stdioConsole::stdioConsole()
  :activity_pin(this, & stdioConsole::read),
   stdout_pin(this, & stdioConsole::write)
{
  add_pin("poll", &activity_pin);
  add_pin("stdin", &stdin_pin);
  add_pin("stdout", &stdout_pin);
  add_attribute_virtual ("state-snapshot", this,
			 & stdioConsole::save_state,
			 & stdioConsole::restore_state);
}

void
stdioConsole::write(host_int_4 value)
{
  cout << static_cast<char> (value) << flush;
}

void
stdioConsole::read(host_int_4)
{
  unsigned char buf[1000];
  int len;
  host_int_4 value;

  // Switch to non-blocking input.
  long flags = fcntl(0, F_GETFL);
  fcntl(0, F_SETFL, flags | O_NONBLOCK);

  if ((len = ::read(0, buf, 1000)) > 0)
    {
      for (int i = 0; i < len; ++i)
	{
	  stdin_pin.drive(buf[i]);
	}
    }

  // Restore flags.
  fcntl(0, F_SETFL, flags);
}


string 
stdioConsole::save_state ( )
{
  return string("console");
}


component::status
stdioConsole::restore_state(const string& state)
{
  if ( state == "console")
    return component::ok;
  else
    return component::bad_value;
}


} // end of namespace console_stuff

