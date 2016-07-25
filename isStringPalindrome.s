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
 * 
 *	%g0 - used as 0 (NULL)
 *	%i0 - the passed in string(arg1)
 *	%l0 - the first char
 *	%l1 - the last char
 *	%l2 - the allocated new string pointer
 *	%l3 - store the length-1(offset) of the string	
 *	%l4 - store the value of length-2 
 *	%i0 - the passed in arg1 and the final return value
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
	! if the length of string is greater than 2
	sub	%o0,1, %l3	!copy (length-1) to %l3
	mov	%i0, %o0	!prepare argument for tolower
	call	tolower
	nop
	mov	%o0, %l0
	ldub	[%i0+%l3], %l1	!load the last char to %l1
	stb	%l1, [%o0]
	call	tolower		!convert the last char to lowercase
	nop
	mov	%o0, %l1
	cmp	%l0, %l1	!compare the first char to last char
	bne	false		!branch if they are not equal
	nop

	!if the first&last chars are equal, compare the middle section
	sub	%l3,1,%l4	!store the value of length-2 in %l4
	!allocate memory for a new string(the middle section)
	mov	%l3, %o0	!we actually need to allocate one more byte
				!to ensure there is terminating byte \0
	mov	1, %o1		!the size of a char is 1 byte
	call	calloc		!call calloc 
	nop
	
	!deal with errors that might occur when calling calloc
	cmp	%o0, 0		!check if calloc fails(return NULL)
	be	error
	nop

	mov	%o0, %l2	!put the allocated memory area in %l2
	!copy the middle section by calling strncpy
	mov	%l2, %o0
	add	%i0,1,%o1	!i0+1 points to the second char in str
	mov	%l4, %o2	!put the number of characters to copy to %o2
	call	strncpy
	nop
	
	!call isStringPalindrome recursively
	mov	%o0, %l5
	mov	%l5, %o0
	call	isStringPalindrome
	nop
	! back from recursion
	mov	%o0, %i0	!put the return value from recursive call
				!back to the final return value
	mov	%l2, %o0
	call	free		!free the previously allocated memory
	nop
	ba	end
	nop
length2:
	ldub	[%i0], %l0	!load the first char to %l0
	ldub	[%i0+1],%l1	!load the second(last) char to %l2
	mov	%l0, %o0
	call	tolower		!conver the first char to lowercase
	nop
	mov	%o0, %l0	!store the lowercased first char back 
	mov	%l1, %o0	
	call	tolower		!convert the second char to lowercase
	nop
	mov	%o0, %l1	!store the lowercased second char back
	cmp	%l0, %l1
	be	true		!branch to true if these two chars are equal
	nop
		

false:
	mov	0,%i0		!return 0 for false
	ba	end
	nop
	
true:	
	mov	1,%i0		!return 1 for true
	ba	end
	nop

error:
	mov	%g0, %o0
	call	perror
	nop
	ba	false		!after calling perror, return 0
	nop
end:	
	nop
	ret			!return from the subroutine
	restore			!restore caller's window
