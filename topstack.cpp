/*
 * Blazing Griffin code test
 * Part 2 : Data structures
 *
 * Trevor Fountain
 * April 2013
 */

#include <stdio.h>
#include <stack>

/**
@brief TopStack provides the standard push/pop stack methods, plus an additional
       `getHighest()` method that returns the highest-valued int currently on 
       the stack.

Feel free to make additions to the class definition, but justify any 
modifications to the existing methods!
*/
class TopStack
{
	protected:
		std::stack<int> stack;
	public:
		/// Push a value onto the top of the stack
		void push(int value);

		/// Remove the topmost value from the stack and return it
		int pop();

		/// Return the highest value currently on the stack
		int getHighest();
};

void TopStack::push(int value)
{
	// Implement me!
}

int TopStack::pop()
{
	// Implement me!
	return 0;
}

int TopStack::getHighest()
{
	// Implement me!
	return 0;
}

int main(int argc, char **argv)
{
	bool pass = true;

	TopStack topStack;

	topStack.push(12);
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(6);
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(42);
	pass = pass && (topStack.getHighest() == 42);

	topStack.pop();
	pass = pass && (topStack.getHighest() == 12);

	printf("%s\n", pass ? "PASS" : "FAIL");

	return 0;
}