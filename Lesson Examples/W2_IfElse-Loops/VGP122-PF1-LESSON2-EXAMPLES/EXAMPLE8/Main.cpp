#include <iostream>

int main()
{
	int product = 3;

	std::cout << "The value of product is " << product << std::endl;

	while (product <= 100)
	{
		product *= 3;

		std::cout << "The value of product is " << product << std::endl;
	}

	return 0;
}