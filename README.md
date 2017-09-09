# Project Overview

 This project is a personal programming assignment from the course **Computer Organization and System Programming"" at 
 **UC San Diego**. The goal of the course overall is to help us learn the basics of **x86 assembly** and along with some **C** 
 programming. The palindrome.c program is simple and straightforward, but the real challenge lies in where we, as students, had
 to translate the program from **C** to **assembly**. Today, assembly language is used primarily for direct hardware manipulation,
 access to specialized processor instructions, or to address critical performance issues. Typical uses are **device drivers**, 
 **low-level embedded systems**, and **real-time systems**.
 
 
 # Language
  This program consists both **C** and **assembly** language




# Date: 07/25/2016




**What I did**:
1. This program would take in input, either from a file or from the keyboard, and 
   determine if it is a **palindrome**.
   Palindrome means a word reads forward the same as it reads backward.
   The program can act differently depending on how the user specify options.
   It can read the word as it is and it can also check the word on its bits level to 
   see if the byte patterns are palindromes.
   In the end, the program would print out the tracked number of total palindromes 	
   found to the terminal.

2. With the supplied **Makefile** from the public directory, just type in “**make**” in the 
   command line to compile all source files.

3. To run the program, assuming the executable name is palindrome, type something as 
   the following:
	$./palindrome -s -f testfile1

   The above will set the option flag to treat input as string(char array) and read 
	in input from file named tesfile1

4.The normal output goes to stdout.
   ex: 
[cs30ubp@ieng9]:pa3:548$ ./palindrome -b 
r
"r" is not a Binary palindrome
R
"R" is not a Binary palindrome
B
"B" is a Binary palindrome
RJ
"RJ" is a Binary palindrome
T~*
"T~*" is a Binary palindrome
<
"<" is a Binary palindrome
.
"." is not a Binary palindrome
404
"404" is not a Binary palindrome
RBJ
"RBJ" is a Binary palindrome
^D
5 palindromes were seen:
B
RJ
T~*
<
RBJ

5. Abnormal output goes to stderr.

ex:
[cs30ubp@ieng9]:pa3:559$ ./palindrome -b -f avsvv
avsvv: No such file or directory



6. First of all, I have to test for different option flags. 
   For example, I need to make sure only either one of -b or -s is specified,not  both. If both are specified, the program have to print out error message and return.
   When -f is specified, make sure to use perror to handle cases like invalid/non-existent file input.

   In addition to correctly outputting results for testfiles, I also have to test
   for the inputs from keyboard. All inputs must be recorded and checked by calling 
   my palindrome functions and print out the results when ctrl+D is typed in.

7. Make sure to compile all files on **SPARC** machines with the provided Makefile.


# Author 
[@Daniel](https://www.linkedin.com/in/daniel-huang-443546115/)
 
