#
# tabnotebook.tcl
#
# ----------------------------------------------------------------------
# Bindings for the BLT tabnotebook widget
# ----------------------------------------------------------------------
#   AUTHOR:  George Howlett
#            Bell Labs Innovations for Lucent Technologies
#            gah@bell-labs.com
#            http://www.tcltk.com/blt
# ----------------------------------------------------------------------
# Copyright (c) 1998  Lucent Technologies, Inc.
# ======================================================================
#
# Permission to use, copy, modify, and distribute this software and its
# documentation for any purpose and without fee is hereby granted,
# provided that the above copyright notice appear in all copies and that
# both that the copyright notice and warranty disclaimer appear in
# supporting documentation, and that the names of Lucent Technologies
# any of their entities not be used in advertising or publicity
# pertaining to distribution of the software without specific, written
# prior permission.
#
# Lucent Technologies disclaims all warranties with regard to this
# software, including all implied warranties of merchantability and
# fitness.  In no event shall Lucent be liable for any special, indirect
# or consequential damages or any damages whatsoever resulting from loss
# of use, data or profits, whether in an action of contract, negligence
# or other tortuous action, arising out of or in connection with the use
# or performance of this software.
#
# ======================================================================

#
# Indicates whether to activate (highlight) tabs when the mouse passes
# over them.  This is turned off during scan operations.
#
set bltTabnotebook(activate) yes

# ----------------------------------------------------------------------
# 
# ButtonPress assignments
#
#   <ButtonPress-2>	Starts scan mechanism (pushes the tabs)
#   <B2-Motion>		Adjust scan
#   <ButtonRelease-2>	Stops scan
#
# ----------------------------------------------------------------------
bind Tabnotebook <B2-Motion> {
    %W scan dragto %x %y
}

bind Tabnotebook <ButtonPress-2> {
    set bltTabnotebook(cursor) [%W cget -cursor]
    set bltTabnotebook(activate) no
    %W configure -cursor hand1
    %W scan mark %x %y
}

bind Tabnotebook <ButtonRelease-2> {
    %W configure -cursor $bltTabnotebook(cursor)
    set bltTabnotebook(activate) yes
    %W highlight @%x,%y
}

# ----------------------------------------------------------------------
# 
# KeyPress assignments
#
#   <KeyPress-Up>	Moves focus to the tab immediately above the 
#			current.
#   <KeyPress-Down>	Moves focus to the tab immediately below the 
#			current.
#   <KeyPress-Left>	Moves focus to the tab immediately left of the 
#			currently focused tab.
#   <KeyPress-Right>	Moves focus to the tab immediately right of the 
#			currently focused tab.
#   <KeyPress-space>	Invokes the commands associated with the current
#			tab.
#   <KeyPress-Return>	Same as above.
#   <KeyPress>		Go to next tab starting with the ASCII character.
#
# ----------------------------------------------------------------------
bind Tabnotebook <KeyPress-Up> { blt::SelectTab %W "up" }
bind Tabnotebook <KeyPress-Down> { blt::SelectTab %W "down" }
bind Tabnotebook <KeyPress-Right> { blt::SelectTab %W "right" }
bind Tabnotebook <KeyPress-Left> { blt::SelectTab %W "left" }
bind Tabnotebook <KeyPress-space> { %W invoke focus }
bind Tabnotebook <KeyPress-Return> { %W invoke focus }

bind Tabnotebook <KeyPress> {
    if { [string match {[A-Za-z0-9]*} "%A"] } {
	blt::FindMatchingTab %W %A
    }
}

# ----------------------------------------------------------------------
#
# FirstMatchingTab --
#
#	Find the first tab (from the tab that currently has focus) 
#	starting with the same first letter as the tab.  It searches
#	in order of the tab positions and wraps around. If no tab
#	matches, it stops back at the current tab.
#
# Arguments:	
#	widget		Tabnotebook widget.
#	key		ASCII character of key pressed
#
# ----------------------------------------------------------------------
proc blt::FindMatchingTab { widget key } {
    set key [string tolower $key]
    set itab [$widget index focus]
    set numTabs [$widget size]
    for { set i 0 } { $i < $numTabs } { incr i } {
	if { [incr itab] >= $numTabs } {
	    set itab 0
	}
	set label [string tolower [$widget tab cget $itab -text]]
	if { [string index $label 0] == $key } {
	    break
	}
    }
    $widget focus $itab
    $widget see focus
}

# ----------------------------------------------------------------------
#
# SelectTab --
#
#	Invokes the command for the tab.  If the widget associated tab 
#	is currently torn off, the tearoff is raised.
#
# Arguments:	
#	widget		Tabnotebook widget.
#	x y		Unused.
#
# ----------------------------------------------------------------------
proc blt::SelectTab { widget tab } {
    set index [$widget index $tab]
    if { $index != "" } {
	$widget select $index
	$widget focus $index
	$widget see $index
	set w [$widget tab tearoff $index]
	if { ($w != "") && ($w != "$widget") } {
	    raise [winfo toplevel $w]
	}
	$widget invoke $index
    }
}

# ----------------------------------------------------------------------
#
# DestroyTearoff --
#
#	Destroys the toplevel window and the container tearoff 
#	window holding the embedded widget.  The widget is placed
#	back inside the tab.
#
# Arguments:	
#	widget		Tabnotebook widget.
#	tab		Tab selected.
#
# ----------------------------------------------------------------------
proc blt::DestroyTearoff { widget tab } {
    set id [$widget id $tab]
    set top "$widget.toplevel-$id"
    if { [winfo exists $top] } {
	wm withdraw $top
	update
	$widget tab tearoff $tab $widget
	destroy $top
    }
}

# ----------------------------------------------------------------------
#
# CreateTearoff --
#
#	Creates a new toplevel window and moves the embedded widget
#	into it.  The toplevel is placed just below the tab.  The
#	DELETE WINDOW property is set so that if the toplevel window 
#	is requested to be deleted by the window manager, the embedded
#	widget is placed back inside of the tab.  Note also that 
#	if the tabnotebook container is ever destroyed, the toplevel is
#	also destroyed.  
#
# Arguments:	
#	widget		Tabnotebook widget.
#	tab		Tab selected.
#	x y		The coordinates of the mouse pointer.
#
# ----------------------------------------------------------------------
proc blt::CreateTearoff { widget tab rootX rootY } {

    # ------------------------------------------------------------------
    # When reparenting the window contained in the tab, check if the
    # window or any window in its hierarchy currently has focus.
    # Since we're reparenting windows behind its back, Tk can
    # mistakenly activate the keyboard focus when the mouse enters the
    # old toplevel.  The simplest way to deal with this problem is to
    # take the focus off the window and set it to the tabnotebook widget
    # itself.
    # ------------------------------------------------------------------

    set focus [focus]
    set window [$widget tab cget $tab -window]
    set index [$widget index $tab]
    if { ($focus == $window) || ([string match  $window.* $focus]) } {
	focus -force $widget
    }
    set id [$widget id $index]
    set top "$widget.toplevel-$id"
    toplevel $top
    $widget tab tearoff $tab $top.container
    table $top $top.container -fill both

    incr rootX 10 ; incr rootY 10
    wm geometry $top +$rootX+$rootY

    set parent [winfo toplevel $widget]
    wm title $top "[wm title $parent]: [$widget tab cget $index -text]"
    wm transient $top $parent

    # If the user tries to delete the toplevel, put the window back
    # into the tab folder.  

    wm protocol $top WM_DELETE_WINDOW [list blt::DestroyTearoff $widget $tab]

    # If the container is ever destroyed, automatically destroy the
    # toplevel too.  

    bind $top.container <Destroy> [list destroy $top]
}

# ----------------------------------------------------------------------
#
# ToggleTearoff --
#
#	Toggles the tab tearoff.  If the tab contains a embedded widget, 
#	it is placed inside of a toplevel window.  If the widget has 
#	already been torn off, the widget is replaced back in the tab.
#
# Arguments:	
#	widget		tabnotebook widget.
#	x y		The coordinates of the mouse pointer.
#
# ----------------------------------------------------------------------
proc blt::ToggleTearoff { widget x y index } {
    set tab [$widget index $index]
    if { $tab == "" } {
	return
    }
    $widget invoke $tab

    set container [$widget tab tearoff $index]
    if { $container == "$widget" } {
	blt::CreateTearoff $widget $tab $x $y
    } elseif { $container != "" } {
	blt::DestroyTearoff $widget $tab
    }
}

# ----------------------------------------------------------------------
#
# TabnotebookInit
#
#	Invoked from C whenever a new tabnotebook widget is created.
#	Sets up the default bindings for the all tab entries.  
#	These bindings are local to the widget, so they can't be 
#	set through the usual widget class bind tags mechanism.
#
#	<Enter>		Activates the tab.
#	<Leave>		Deactivates all tabs.
#	<ButtonPress-1>	Selects the tab and invokes its command.
#	<Control-ButtonPress-1>	
#			Toggles the tab tearoff.  If the tab contains
#			a embedded widget, it is placed inside of a
#			toplevel window.  If the widget has already
#			been torn off, the widget is replaced back
#			in the tab.
#
# Arguments:	
#	widget		tabnotebook widget
#
# ----------------------------------------------------------------------
proc blt::TabnotebookInit { widget } {
    $widget bind all <Enter> { 
	if { $bltTabnotebook(activate) } {
	    %W highlight current
        }
    }
    $widget bind all <Leave> { 
        %W highlight "" 
    }
    $widget bind all <ButtonPress-1> { 
	blt::SelectTab %W "current"
    }
    $widget bind all <Control-ButtonPress-1> { 
	blt::ToggleTearoff %W %X %Y active
    }
    $widget configure -perforationcommand {
	blt::ToggleTearoff %W $bltTabnotebook(x) $bltTabnotebook(y) select
    }
    $widget bind Perforation <Enter> { 
	%W perforation highlight on
    }
    $widget bind Perforation <Leave> { 
	%W perforation highlight off
    }
    $widget bind Perforation <ButtonPress-1> { 
	set bltTabnotebook(x) %X
	set bltTabnotebook(y) %Y
	%W perforation invoke
    }
}
