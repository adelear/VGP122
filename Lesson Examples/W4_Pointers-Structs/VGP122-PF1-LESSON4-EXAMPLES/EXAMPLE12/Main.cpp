#include <iostream>

int square(int);

int main()
{
	int i;

	std::cout << "Enter an integer: ";
	std::cin >> i;

	std::cout << "The square of i is " << square(i) << std::endl;

	return 0;
}

int square(int x)
{
	return x * x;
}