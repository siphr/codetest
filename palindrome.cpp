/*
 * Blazing Griffin code test
 * Part 1 : Palindromes
 *
 * Trevor Fountain
 * April 2013
 */

#include <stdio.h>
#include <string.h>

bool isPalindrome(const char *string)
{
	// assuming string is null terminated
	size_t count = strlen(string);

	// I only need to iterate through half of the string.
	// using integer division as I do not care about the middle character in case of odd length strings
	const size_t half_count = count/2;	

	//printf("%lu\n",count);

	// starting for the last element
	count--;

	// for each character upto half string length...
	for (size_t i=0; i < half_count; count--, i++)
	{
		//printf("%c\n", *(string+i));
		//printf("%c\n", *(string+count));

		// ... check if it matches the character at the mirrored position at the end
		if (*(string+i) != *(string + count))
		{
			return false;
		}
	}
	
	return true;
}

int main(int argc, char **argv)
{
	bool pass = 
		isPalindrome("racecar") &&
		!isPalindrome("notapalindrome") &&
		isPalindrome("aaaaAAAAaaaa") &&
		!isPalindrome("((((())))))") &&
		isPalindrome("FOO OOF");

	printf("%s\n", pass ? "PASS" : "FAIL");

	return 0;
}
