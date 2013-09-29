FFT
===

Fortran Format Tool for Text Files

DEPENDENCIES
============

g++,gfortran,libwxbase2.8-dev

INSTALL
=======

Use 'make' command to compile program. 
Use 'sudo make install' if you want to install program to your system.

USAGE
=====

Start using program with opening an input file or enter the input text into 
large textcontrol at the left. If you opened an input file, variables 
and Fortran format of input will be detected automatically. If you enter the 
input text manually, use Action >> Handle Input menu or Ctrl+I shortcut to 
automatic detection.

After detection process (you can change input anytime and use Handle Input 
again) you can modify output variables and Fortran format and use Action >> Run 
or Ctrl+R to run the program. Output will be written into large textcontrol 
at the right. At last you can see the produced fortran file in the ~/.fft 
folder if you wish.

CONTACT
=======

Feel free to write e-mails about feature requests and bugs.
Bora CANBULA <bc.jabba@gmail.com>
