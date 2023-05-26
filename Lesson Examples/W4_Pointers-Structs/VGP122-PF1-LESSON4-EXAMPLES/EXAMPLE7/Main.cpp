#include <iostream>

int main()
{
	int a = 5;
	int b = 2;

	double test;

	//Division of two integers produces an integer
	test = a / b;

	std::cout << test << std::endl << std::endl;

	//Division of two doubles produces a double
	test = (double)a / (double)b;

	std::cout << test << std::endl << std::endl;

	//Division of two doubles produces a double
	test = static_cast<double>(a) / static_cast<double>(b);

	std::cout << test << std::endl << std::endl;

	return 0;
}