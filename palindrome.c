/*
 * Filenmae: palindrome.c
 * Author: Daniel Huang
 * Userid: cs30ubp
 * Description: The main C code for the program
 * Date: 07/22/2016
 * Sources of help: PIAZZA
 */

#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"




/*
 * Function name: main()
 * Function prototype: int main(int argc,char *argv[]);
 * Description: The main function that process command line arguments
 * Parameters:
 *    arg1 - int argc - the number of passed in arguments
 *    arg2 - char *argv[] - the string array that represents all
 *                          arguments
 * Return: 1 if exit successfully; -1 otherwise
 */
int main(int argc, char *argv[])
{

  /*opt represents the option that is recognized and returned by getopt*/
  int opt;
  int flag;
  while((opt=getopt(argc, argv, OPT_STRING))!=-1){
    
    if((opt=='s'||opt=='b')&&flag!=0)
    {  /*flag has already been set*/
      
        (void)fprintf(stderr,EXCLUSIVE_ARGS);
        return EXIT_FAILURE;
    }
    
    if(opt=='b'&&flag==0)   
    {
      flag=BFLAG; /*set the flag*/
      }
    else if(opt=='s'&&flag==0)

    {
      flag=SFLAG; /*set the flag*/
      }
    if(opt=='f')
    {
      /*open the file specified in command line*/
      printf("need to open some file\n");
      }
    }
printf("the flag is set to be %d\n", flag);




  return EXIT_SUCCESS;
 }
