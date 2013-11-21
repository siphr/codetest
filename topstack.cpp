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
#include <exception>

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
        /// Additional stack for maintaining maxes. This should not be as bad as doubling space but in
        /// worst case scenario it can be.
        std::stack<int> maxes;

	public:

        /// A generic stack exception class
        class stack_exception : public std::exception
        {
            public:
                stack_exception(const char* const method, const char* const exception) :
                    m_exception(std::string(method) + ": " + exception)
                { }

                virtual ~stack_exception() throw() { }

                const char* what() const throw()
                {
                    return m_exception.c_str();
                }
                
            private:
                const std::string m_exception;
        };

		/// Push a value onto the top of the stack
		void push(int value);

		/// Remove the topmost value from the stack and return it
		int pop();

		/// Return the highest value currently on the stack
		int getHighest();
};

/**
 * \brief
 * Pushes an element onto a stack.
 *
 * \details
 * keeps track of current maximum on the stack by maintaining the maxes stack.
 *
 * \param[in] value
 * Integer value to push onto the stack.
 */
void TopStack::push(int value)
{
    stack.push(value);

    // update max value stack if it is the first item or the value is greater than our existing recorded high
    // value.
    if (maxes.empty() || value >= maxes.top())
    {
            maxes.push(value);
    }
}

/**
 * \brief
 * Pop an item out of the stack.
 *
 * \details
 * Pops an item while keeping track of the left over max values in the stack.
 *
 * \return
 * Popped integer value.
 *
 * \throws stack_exception
 * If the stack is empty.
 */
int TopStack::pop()
{
    if (stack.empty())
    {
        throw stack_exception(__FUNCTION__ ,"Cannot pop an item when the stack is empty.");
    }

	const int value = stack.top();
	stack.pop();

    // if the popped value is also the currently recorded highest then remove it.
    if (value == maxes.top())
    {
        maxes.pop();
    }

	return value;
}

/**
 * \brief
 * Returns the current recorded maximum value on the stack.
 *
 * \return
 * Highest value on the stack.
 *
 * \throws stack_exception
 * If the maxes stack is empty.
 */
int TopStack::getHighest()
{
    if (maxes.empty())
    {
        throw stack_exception(__FUNCTION__ ,"Cannot get highest value when the stack is empty.");
    }

	return maxes.top();
}

int main(int argc, char **argv)
{
	bool pass = true;

	TopStack topStack;

    // testing for empty stack.
    try
    {
        topStack.pop();
    }
    catch(const TopStack::stack_exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    // testing for empty stack.
    try
    {
        topStack.getHighest();
    }
    catch(const TopStack::stack_exception& e)
    {
        std::cout << e.what() << std::endl;
    }

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
