all: palindrome topstack galaxy

palindrome: palindrome.cpp
	g++ palindrome.cpp -o palindrome && ./palindrome

topstack: topstack.cpp
	g++ topstack.cpp -o topstack && ./topstack

galaxy: galaxy.cpp
	g++ galaxy.cpp -o galaxy && ./galaxy