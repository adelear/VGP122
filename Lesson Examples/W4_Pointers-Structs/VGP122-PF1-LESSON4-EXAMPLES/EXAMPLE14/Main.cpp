#include <iostream>

void swap(int*);

int main()
{
	int* numList = new int[2];

	std::cout << "Enter an integer: ";
	std::cin >> numList[0];

	std::cout << "Enter another integer: ";
	std::cin >> numList[1];

	swap(numList);

	std::cout << "After swapping, the value of numList[0] is " << numList[0] << " and the value of numList[1] is " << numList[1] << std::endl << std::endl;

	delete[] numList;

	return 0;
}

void swap(int* array)
{
	int temp;

	temp = array[0];
	array[0] = array[1];
	array[1] = temp;
}