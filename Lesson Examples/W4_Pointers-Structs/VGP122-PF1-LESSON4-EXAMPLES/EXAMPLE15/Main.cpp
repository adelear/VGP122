#include <iostream>

int sum(const int*, const int);

int main()
{
	int nums;
	int* numList;

	std::cout << "Enter the number of integers to add: ";
	std::cin >> nums;

	numList = new int[nums];

	for (int i = 0; i < nums; ++i)
	{
		std::cout << "Enter number " << (i + 1) << ": ";
		std::cin >> numList[i];
	}

	std::cout << "The sum of the numbers is " << sum(numList, nums) << std::endl;

	delete[] numList;

	return 0;
}

int sum(const int* array, const int length)
{
	int total = 0;

	for (int i = 0; i < length; ++i)
	{
		total += array[i];
	}

	return total;
}