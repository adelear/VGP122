#include <iostream>

#include "Globals.h"

int main()
{
	std::cout << "Enter a number: ";
	std::cin >> a;

	std::cout << "Enter another number: ";
	std::cin >> b;

	c = a + b;

	std::cout << "The sum of a + b = " << c << std::endl;

	return 0;
}