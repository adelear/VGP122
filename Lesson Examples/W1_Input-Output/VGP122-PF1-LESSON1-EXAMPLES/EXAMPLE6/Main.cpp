#include <iostream>

int main()
{
	int x = 4;
	int y = 2;

	//Arithmetic Addition
	std::cout << "x + y = " << (x + y) << std::endl;

	//Arithmetic Subtraction
	std::cout << "x - y = " << (x - y) << std::endl;

	//Arithmetic Multiplication
	std::cout << "x * y = " << (x * y) << std::endl;

	//Arithmetic Division
	std::cout << "x / y = " << (x / y) << std::endl;

	//Arithmetic Modulus
	std::cout << "x % y = " << (x % y) << std::endl;

	//Arithmetic Pre-Increment
	std::cout << "++x = " << ++x << std::endl;

	//Arithmetic Post-Increment
	std::cout << "x++ = " << x++ << std::endl;

	//Arithmetic Pre-Decrement
	std::cout << "--x = " << --x << std::endl;

	//Arithmetic Post-Decrement
	std::cout << "x-- = " << x-- << std::endl;

	//Arithmetic Addition and Assignment
	std::cout << "x += y = " << (x += y) << std::endl;

	//Arithmetic Subtraction and Assignment
	std::cout << "x -= y = " << (x -= y) << std::endl;

	//Arithmetic Multiplication and Assignment
	std::cout << "x *= y = " << (x *= y) << std::endl;

	//Arithmetic Division and Assignment
	std::cout << "x /= y = " << (x /= y) << std::endl;

	//Arithmetic Modulus and Assignment
	std::cout << "x %= y = " << (x %= y) << std::endl;

	return 0;
}