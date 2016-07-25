/*
 * Filename: areBytesReversed.c
 * Author: Daniel Huang
 * Userid: cs30ubp
 * Description: This file contains the function that will be called in 
 *              isBinaryPalindrome.c to determine if two bytes are the
 *              reverse of each other at the bit level
 * Date: 07/24/2016
 * Sources of help: None
 */


#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"


/* Function name: areBytesReversed()
 * Function prototype: int areBytesReversed(unsigned char byte1, 
 *                      unsigned char byte2);
 * Parameters: 
 *  arg1 - unsigned char byte1- the first byte to be compared
 *  arg2 - unsigned char byte2- the second byte to be compared
 * Side Effect: None
 * Error Conditions: None
 * Return: return 1 for true; 0 for false
 */

 int areBytesReversed(unsigned char byte1, unsigned char byte2){

if(byte1==byte2)
{
  return 1;
}

    return 0;




 }
