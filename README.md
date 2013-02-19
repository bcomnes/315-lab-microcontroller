315-lab-microcontroller
=======================

This is a lab write-up I put together for Portland State University's Physics 315 class.  Its based off a prior student, Marshal Colville's, work.  It adds more instruction and background.  

Originally written in LaTeX, the main micro-controller lab was converted to Word, so now it is missing edits from the version used in class.  I plan to eventually get those changes in.

A quick PID .ino program was put together to address some of the usability issues found in Marshal's original write up.  It allows for monitoring of the PID loop over the serial line, as well as runtime updating of the gain constants.

## Dependencies  

The .tex files require --shell-escape set, and it also uses pygments for colorization.  This requires a working copy of python and and pygmentize installed. I recommend using `pip` to install pygments.   After that, the LaTeX should just work.

The schematics were done using fritzing, although remind me to avoid that program in the future.
