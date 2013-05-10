/*
 * Blazing Griffin code test
 * Part 1 : Palindromes
 *
 * Trevor Fountain
 * April 2013
 */

#include <stdio.h>

bool isPalindrome(const char *string)
{
	// Implement me!
	return false;
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