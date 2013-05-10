# Blazing Griffin Code Test

## Part 1: Palindromes

`palindrome.cpp` defines a function, `isPalindrome()`, that takes a C-style 
string and returns a boolean indicating whether or not the string is a 
palindrome (a string that's the same read forwards or backwards). 

Implement `isPalindrome()`!

> Note: "abccba" and "abcba" are palindromes; "ABCcba" is not

## Part 2: Data Structures

`topstack.cpp` defines a class, `TopStack`, which implements a stack of (signed)
integers. It has the standard stack methods `push` and `pop`, plus an additional
method `getHighest` that should return the highest-valued integer currently on
the stack.

Implement `push()`, `pop()`, and `getHighest()`!

> Note: justify any changes made to TopStack's class definition.

## Part 3: Game Logic

`galaxy.cpp` defines a class, `Galaxy`, which holds information about stars 
(points in space) and lanes (connections between stars).

Implement the `Galaxy::getRouteBetween()` method so that it takes two Stars and 
finds the shortest route between them.

> Note: the 'shortest route' between two stars is the route that passes through
> the fewest number of stars.