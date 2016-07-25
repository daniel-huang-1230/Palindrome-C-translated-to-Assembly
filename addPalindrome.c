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
    (void)strncpy(newStr,str,strlen(str));
   
   /*make a pointer to the string that is going to be added*/
/*    &newStr=malloc(strlen(str));*/
    /*extend space*/
  void *ptr;
   ptr=realloc(*(seen->palindrome), (seen->number)+1);
  if(ptr==NULL) {
    char *str="";
   perror(str);
  }
  seen->palindrome[seen->number]=newStr;

  (void)memcpy((seen->palindrome)[seen->number],newStr,strlen(newStr));
   /*place the new string ptr to the index determined by current
                                              palindromes number*/

    seen->number++; /*increment the palindromes count*/
    /*don't forget to free memory*/
    free(newStr);
    free(ptr);  
  }
