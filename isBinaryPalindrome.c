/*
 * Filename: isBinaryPalindrome.c
 * Author: Daniel Huang
 * Userid: cs30ubp
 * Description: This C code will treat each byte as a sequence of bits and
 *              determine if the bit patterns is a palindrome
 * Date: 07/24/2016
 * Sources of help: None
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"




/* Function name: isBinaryPalindrome()
 * Function prototype: int isBinaryPalindrome(const char* const str)
 * Parameters: 
 *  arg1 - const char* const str - the passed in string to be checked
 *         if it is a palindrome in termes of bit patterns
 * Side Effects: None
 * Error Conditions: None
 * Return: return 1 for true; 0 for false
 */

#define TWO 2 /*to avoid magic number/hard-coding*/
int isBinaryPalindrome(const char* const str) {

  /*first make sure the passed in str is not NULL*/
  if(str==NULL){

    return 0;
  }
  int strLength;
  strLength=strlen(str);
  /*if the string lenght is 1, check the single char*/
  if(strLength==1) {

    if(areBytesReversed(*str,*str)==1) {
      return 1;
    }
    else {
      return 0;
    }
  }

  if(strLength==TWO) {
    if(areBytesReversed(*str, *(str+strLength-1))==1) {

      return 1;
    }
    else {

      return 0;
    }
  }
  /*if the string length is greater than 2*/
  if(areBytesReversed(*str,*(str+strLength-1))==0) {

    return 0; /*return 0 for false*/
  }
  else {
    /*if the first and last char are bytes reverse of each other*/
    /*need to allocate memory for a new string*/
    char *newStr;
    newStr=calloc(strLength-1,sizeof(char));
    if(newStr==NULL) {
      char* errStr=" ";
      perror(errStr); /*call perror and exit if calloc fails*/
      return EXIT_FAILURE;
    }
    /*call isBinaryPalindrome recursively*/
    int ret;/*store the return value*/
    ret=isBinaryPalindrome (memcpy(newStr,str+1,strLength-TWO));
    free(newStr); /*free the allocated memory*/
    return ret;
  }




}
