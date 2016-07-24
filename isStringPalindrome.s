/*
 * Filename: isStringPalindrome.s
 * Author: Daniel Huang
 * Userid: cs30ubp
 * Description: The assembly routime that is responsible for the checking 
 *		if the given string is a palindrome
 * Date: 07/24/2016
 * Sources of help: PIAZZA
 */

 	.global	isStringPalindrome	!Declare the symbol to be globally
					!visible


	.section ".text"		!The text segment begins here	



/*
 * Function name:isStringPalindrome()
 * Function prototype:int isStringPalindrome(const char* const str);
 * Description: This function would determine if the passed in string
 *		is a palindrome;it is implemented recursively
 * Parameters:
 *	arg1 - the passed in string
 * Side Effects: None
 * Error Conditions: None
 * Return: 1 if true; 0 otherwise
 * Registers Used:
 * TODO
 *	%i0 - the passed in string(arg1)
 *
 */

 isStringPalindrome:
 	save	%sp, -96, %sp	!Dynamically allocate memory on heap,
				!so no need to save additional space in stack
	!first check if the str is null
	cmp	%i0, 0	
	be	false
	nop
	
	mov	%i0,%o0		!prepare arguments for strlen
	call	strlen		!call strlen
	nop
	cmp	%o0, 0
	be	false
	nop
	cmp	%o0, 1		!check if the string length=1
	be	true
	nop
	
	cmp	%o0, 2		!check if the string length=2
	be	length2
	nop

length2:

false:
	mov	0,%i0		!return 0 for false
	ba	end
	nop
	
true:
	mov	1,%i0		!return 1 for true
	ba	end
	nop

end:
	ret
	restore
