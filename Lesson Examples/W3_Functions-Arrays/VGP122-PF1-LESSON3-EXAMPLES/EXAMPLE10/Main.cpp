#include <iostream>

int maximum(int, int, int);

int main()
{
	int x, y, z;

	std::cout << "Enter three numbers: ";
	std::cin >> x >> y >> z;

	std::cout << "The highest number is " << maximum(x, y, z) << std::endl;

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