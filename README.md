=====================================================

		      README

=====================================================

*****************************************************

		      ABOUT

*****************************************************

	Do you use different editors to edit your 
programs depending on where you are?

	Do some of your editors use tabs and some
use spaces? Well look no further!

	Especially if you are using a whitespace 
separated language such as python, those Tab and
whitespace errors can be a nuisance.

	Fix tabs aims to fix your tab situation
for you, just indicate whether you want to use
tabs or spaces, and fix tabs will change your
file to replace the tabs and spaces to your 
liking

**********************************************

		   HOW TO

**********************************************

Right now fix_tabs is a command line program.
In order to build it:

- Download all the files
- open command line and cd to directory with
the files
- run "make"
- if you want to remove .o files run "make
clean"

**********************************************

		VERSION 0.1

**********************************************

- fix_tabs can now convert tabs to spaces

- NUM_SPACES_FOR_TABS is 4 by default
in fix_tabs.c

- fix_tabs does not deal with files that 
do not have the same number of spaces per
indent

*********************************************

             PLANS FOR FUTURE

*********************************************

- want to be able to convert tabs to spaces

- want to be able to deal with mixed 
indentation

- want to be able to deal with files that 
do not use the same number of spaces for
a tab (hopefully by mistake)

- refactor code


**********************************************

		KNOWN BUGS

**********************************************

