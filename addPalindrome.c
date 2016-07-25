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
#include <string.h>

/* Function name: addPalindrome()
 * Function prototype: void addPalindrome(struct palindromes * seen, 
 *                     const char * str);
 * Description: The function keeps track of the palindromes seen
 * Parameters:
 *   arg1 - struct palindromes* seen - a pointer to the palindromes 
 *                                     struct
 *   arg2 - const char* str - the passed in string; need to allocate 
 *                             memory for it
 * Side Effects: None
 * Error Conditions: None
 * Return: None
 */


void addPalindrome(struct palindromes * seen, const char * str){

  /*allocate space for the passed in string*/

  char *newStr;
  newStr=calloc(strlen(str),sizeof(char));
  /*print the error message if calloc fails*/
  if(newStr==NULL) {
    char* errStr="";
    perror(errStr);
  }
  (void)strncpy(newStr,str,strlen(str)+1);

  /* char ** strArrPtr=malloc(seen->number);
     strArrPtr=seen->palindrome;*/

  /*extend space*/
  char **ptr;
  ptr=realloc(seen->palindrome, sizeof(char *)*((seen->number)+1));
  if(ptr==NULL) {
    char *str="";
    perror(str);
  }

  ptr[seen->number]=newStr;

  /*place the new string ptr to the index determined by current
    palindromes number*/
  seen->palindrome=ptr;
  seen->number++; /*increment the palindromes count*/
  /*don't forget to free memory*/
}
