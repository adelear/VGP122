#include <iostream>

int square(int);

int main()
{
	int a;

	std::cout << "Enter a number: ";
	std::cin >> a;

	std::cout << a << " squared: " << square(a) << std::endl;

	return 0;
}

int square(int x)
{
	return x * x;
}