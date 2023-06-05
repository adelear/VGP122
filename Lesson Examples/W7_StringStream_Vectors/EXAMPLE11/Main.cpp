#include <iostream>

#include "Fraction.h"

int main()
{
	try
	{
		Fraction fraction1("1", "3");
		Fraction fraction2(1, 6);

		std::cout << fraction1 << " + " << fraction2 << " = " << (fraction1 + fraction2) << std::endl << std::endl;
		std::cout << fraction1 << " - " << fraction2 << " = " << (fraction1 - fraction2) << std::endl << std::endl;
		std::cout << fraction1 << " * " << fraction2 << " = " << (fraction1 * fraction2) << std::endl << std::endl;
		std::cout << fraction1 << " / " << fraction2 << " = " << (fraction1 / fraction2) << std::endl << std::endl;
	}
	catch (FractionException& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return 0;
}