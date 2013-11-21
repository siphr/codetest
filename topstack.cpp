/*
 * Blazing Griffin code test
 * Part 2 : Data structures
 *
 * Trevor Fountain
 * April 2013
 */

#include <stdio.h>
#include <stack>
#include <iostream>

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
	// for every value I decided to store the current max
	// consequence of this however is that the memory usage is doubled maintaining linearity

	if (!stack.empty())
	{
		const int prev_max = stack.top();

		if (value > prev_max)
		{
			stack.push(value);
			stack.push(value);
		}
		else
		{
			stack.push(value);
			stack.push(prev_max);
		}
	}
	else
	{
		stack.push(value);
		stack.push(value);
	}

}

int TopStack::pop()
{
	const int max = stack.top();
	stack.pop();

	const int value = stack.top();
	stack.pop();

	return value;
}

int TopStack::getHighest()
{
	return stack.top();
}

int main(int argc, char **argv)
{
	bool pass = true;

	TopStack topStack;

	topStack.push(12);
	std::cout << "12" << ": " << topStack.getHighest() <<  std::endl;
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(6);
	std::cout << "12 6" << ": " << topStack.getHighest() <<  std::endl;
	pass = pass && (topStack.getHighest() == 12);

	topStack.push(42);
	std::cout << "12 6 42" << ": " << topStack.getHighest() <<  std::endl;
	pass = pass && (topStack.getHighest() == 42);

	topStack.pop();
	std::cout << "12 6" << ": " << topStack.getHighest() <<  std::endl;
	pass = pass && (topStack.getHighest() == 12);

	printf("%s\n", pass ? "PASS" : "FAIL");

	return 0;
}
