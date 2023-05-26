#include <iostream>

int main()
{
	std::cout << "The size of an integer variable is " << sizeof(int) << " bytes" << std::endl;
	std::cout << "The size of a short integer variable is " << sizeof(short) << " bytes" << std::endl;
	std::cout << "The size of a long integer variable is " << sizeof(long long) << " bytes" << std::endl;
	std::cout << "The size of a character variable is " << sizeof(char) << " bytes" << std::endl;
	std::cout << "The size of a floating-point variable is " << sizeof(float) << " bytes" << std::endl;
	std::cout << "The size of a double variable is " << sizeof(double) << " bytes" << std::endl;

	std::cout << "The size of a bool variable is " << sizeof(bool) << " bytes" << std::endl;

	return 0;
}