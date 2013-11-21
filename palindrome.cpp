/*
 * Blazing Griffin code test
 * Part 1 : Palindromes
 *
 * Trevor Fountain
 * April 2013
 */

#include <stdio.h>
#include <string.h>


/**
 * \brief
 * Checks to see if the given string is a palindrome.
 *
 * \details
 * Iterates  by i over the string of size s to match character at i against character at s - i.
 * As I do 2 checks per loop I only need to iterate upto half the string length.
 * Odd lengths do not matter hence used integer division.
 * An empty string or a string of single character in this method is assumed to be a palindrome. This could
 * be turned around to return false or even throw an exception.
 *
 * \param[in] string
 * A pointer to null terminated const string.
 *
 * \return
 * True if the word is a palindrome, False otherwise.
 */
bool isPalindrome(const char *string)
{
	// assuming string is null terminated
	size_t count = strlen(string);

    // check if string is empty or of single character
    if (count == 0 || count == 1)
    {
        return true;
    }
    
	// I only need to iterate through half of the string.
	// using integer division as I do not care about the middle character in case of odd length strings
	const size_t half_count = count/2;	

	// Initialising for the last element
	count--;

	// for each character upto half string length...
	for (size_t i=0; i < half_count; count--, i++)
	{
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
		isPalindrome("") &&
		isPalindrome("a") &&
		isPalindrome("racecar") &&
		!isPalindrome("notapalindrome") &&
		isPalindrome("aaaaAAAAaaaa") &&
		!isPalindrome("((((())))))") &&
		isPalindrome("FOO OOF");

	printf("%s\n", pass ? "PASS" : "FAIL");

	return 0;
}
