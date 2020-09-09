# Makefile sample illustrating separate compilation and dependencies.

# Students are welcome to use this as a starter or model, but be sure
# to replace these comments with comments relevant to YOUR assignment
# (including your name and cats login!).  If the reader has to wade
# through "junk comments" you will lose credit.

# Explanatory comments follow the ``real code.''
# Everything after the # on any line is a comment

# ===================================================================
# Here we define a few important "make" variables.
# CFLAGS is platform dependent.  This one is for Linux.

CC     = gcc
CFLAGS = -g -Wall -O0 -std=c99 -D_SVID_SOURCE

# The next line has the first target.  Typing "make" without any names
# causes "make" to default to this target.
# A common first target would read "all: hex shuffle" but this is omitted
# because shuffle.c is not in this directory.
#
hex:	hex.o  readline.o
	${CC}  -o hex  ${CFLAGS} hex.o  readline.o

hex.o:	hex.c  readline.h
	${CC}  -c ${CFLAGS} hex.c

readline.o:	readline.c  readline.h
	${CC}  -c  ${CFLAGS}  readline.c

shuffle:	shuffle.o  readline.o
	${CC}  -o shuffle  ${CFLAGS} shuffle.o  readline.o

shuffle.o:	shuffle.c  readline.h
	${CC}  -c  ${CFLAGS} shuffle.c

# ===================================================================
#
# The rest of this file is a tutorial and should not be submitted.
#
# Makefiles are used by the Unix "make" command.  Do "man make" for
# (too much) information.  A brief summary:

# A "make statement" goes on one or more lines.
# The first of these lines begins in the left margin.
# Subsequent lines of the same "statement" must be indented by
# one tab character (NOT spaces).
# Finally, put a blank line after the whole "statement".
# Make sure you do not have any blanks or tabs at the end of a line.

# THE ABOVE IS VERY IMPORTANT TO FOLLOW STRICTLY ON SOME PLATFORMS.
# READ IT AGAIN.


# Line 1 (the one that is not indented):
#	The format is target_name, colon, dependency_names.
#	White space is flexible.  If this line needs to be continued
#	due to a large number of dependencies, end it with backslash (\).
# Lines 2-n:
#	The format is tab, unix_command (with make variables, maybe).
# WHAT IT MEANS:
#	A "make statement" is like a recursive procedure.  It says:
#	To update target_name
#		first update any of the dependency_name files that are
#		not up to date (use them as recursive target_names).
#
#		Now, if any dependency_name file is NEWER than the
#		target_name file, execute the unix_commands on lines 2-n.
#
#	Being a recursive procedure, it better have a base case.
#	The base cases are dependency_names that do not exist as targets
#	in the Makefile, AND do not conventionally require ``making'',
#	because you, the programmer, create them, often with an editor.
#	Their mere existence makes them up to date.
#
#	Object (.o) files DO require making.
#	Even if you do not include a .o file as a target name,
#	"make" will try (probably not successfully, unless you are a
#	"make" wizard) to make the .o file with a default unix_command,
#	if it does not exist in the current directory.
#
# Normal make commands to issue for this Makefile are "make hex" and
# "make  shuffle", because these are executable programs as opposed to
# modules.  "make" figures out which modules, if any, need to be
# recompiled.  If you want to see what make WOULD do, without actually
# having it do anything, type "make -n hex", etc.

# However, if you want to be sure readline.c compiles correctly, before
# you try to use it as a module in another program, do "make readline.o".
# That is not a typo.  Re-read the previous sentence.

# Running "make" can generate many error messages.  Do
#	make hex >& make.log
# to cause the errors to go into the file make.log.
# When "make" finishes you can read the file with "view", "more", or "less".
#
# Many later error messages can be meaningless because they were caused
# by an earlier error.  Always try to correct errors in order.
