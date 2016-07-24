/*
 * Filename: palinlindrome.h
 * Author: Daniel Huang
 * Description: The header file for this program that contains
 *              definitions and function declarations
 * Date: 07/23/2016
 * Sources of help: None
 */
   
   #ifndef _PALINDROME_H
   #define _PALINDROME_H
  
  #define BFLAG 0x01      /* -b option: Binary palindrome check */
   #define SFLAG 0x02      /* -s option: String palindrome check */
  
  /* Strings */
   #define OPT_STRING "bsf:"
   #define OPEN_MODE "r"
   #define USAGE "\npalindrome -b|-s [-f filename]\n"
   #define EXCLUSIVE_ARGS "Only one of -b or -s options allowed.\n"
   #define MISSING_FLAGS "Either -s or -b must be specified.\n"
   #define TOO_MANY_ARGS "Extra argument: %s\n"
   #define IS_STRING_PALINDROME "\"%s\" is a String palindrome.\n"
   #define NOT_STRING_PALINDROME "\"%s\" is not a String palindrome.\n"
   #define IS_BIN_PALINDROME "\"%s\" is a Binary palindrome\n"
   #define NOT_BIN_PALINDROME "\"%s\" is not a Binary palindrome\n"
   #define SEEN "\n%d palindromes were seen:\n"
   #define NONE_SEEN "\nNo palindromes were seen\n"
   


   
   struct palindromes {
     char ** palindrome;
       int number;
       };
       
       int isStringPalindrome( const char * const str );
       int isBinaryPalindrome( const char * const str );
       int areBytesReversed( unsigned char byte1, unsigned char byte2 );
       void addPalindrome(struct palindromes * seen, const char * str);
       
       #endif /* _PALINDROME_H */
       
       
