#include <iostream>

inline int square(int n)
{
	return n * n;
}

int main()
{
	int n;

	std::cout << "Enter a number: ";
	std::cin >> n;

	std::cout << n << " squared is " << square(n) << std::endl;

	return 0;
}