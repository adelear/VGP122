#include <iostream>

#include "Globals.h"

int main()
{
	int a, b;

	std::cout << "Enter a number: ";
	std::cin >> a;

	std::cout << "Enter another number: ";
	std::cin >> b;

	std::cout << "The lowest number between " << a << " and " << b << " is " << minNumber(a, b) << std::endl;

	return 0;
}