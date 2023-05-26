#include <iostream>

int maximum(int = 0, int = 0, int = 0);

int main()
{
	std::cout << "The highest number is " << maximum() << std::endl;

	std::cout << "The highest number is " << maximum(1) << std::endl;

	std::cout << "The highest number is " << maximum(1, 2) << std::endl;

	std::cout << "The highest number is " << maximum(1, 2, 3) << std::endl;

	return 0;
}

int maximum(int x, int y, int z)
{
	int maxValue = x;

	if (y > maxValue)
		maxValue = y;

	if (z > maxValue)
		maxValue = z;

	return maxValue;
}