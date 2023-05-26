//Addition program
#include <iostream>

int main()
{
	int integer1 = 0; /* first number to be inputted by the user */
	int integer2 = 0; /* second number to be inputted by the user */
	int sum = 0; /* variable where sum will be stored */

	std::cout << "Enter first integer: "; /* prompt */
	std::cin >> integer1;

	std::cout << "Enter second integer: "; /* prompt */
	std::cin >> integer2;

	sum = integer1 + integer2;

	std::cout << "Sum is " << sum << std::endl; /* print sum */

	return 0;
}