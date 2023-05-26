#include <iostream>

int factorial(int);
bool isPrime(int);
bool isPrimeHelper(int, int);

int main()
{
	int number;

	std::cout << "Enter a number: ";
	std::cin >> number;

	std::cout << number << "! is equal to " << factorial(number) << std::endl;

	if (isPrime(number))
		std::cout << number << " is a prime number" << std::endl;
	else 
		std::cout << number << " is not a prime number" << std::endl;

	return 0;
}

int factorial(int x)
{
	if (x == 1)
		return x; 
	
	return x * factorial(x - 1);
}

bool isPrime(int x)
{
	if (x < 2)
		return false;
	else if (x == 2)
		return true;
	else
		return isPrimeHelper(x, (int)ceil(sqrt(x)));
}

bool isPrimeHelper(int x, int d)
{
	if (x < 2)
		return false;

	if (d == 1)
		return true;
	else
	{
		if ((x % d) == 0)
			return false;
		else
			return isPrimeHelper(x, d - 1);
	}
}