/*
 * Filename: addPalindrome.c
 * Author: Daniel Huang
 * Userid: cs30ubp
 * Description: This file contains the function that will be called when a 
 *              palindrome is found.
 * Date: 07/24/2016
 * Sources of help: None
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include "palindrome.h"


 /* Function name: addPalindrome()
  * Function prototype: void addPalindrome(struct palindromes * seen, 
  *                     const char * str);
  *TODO
  */


  void addPalindrome(struct palindromes * seen, const char * str){

  seen->number++;

  printf("%s\n", str);



  }
