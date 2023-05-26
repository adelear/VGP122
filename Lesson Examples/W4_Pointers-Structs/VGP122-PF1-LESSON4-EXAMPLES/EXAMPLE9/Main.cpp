#include <iostream>

int main()
{
	int array[10];
	int* arrayPtr;

	arrayPtr = array;

	std::cout << "The memory address for the array pointer is " << &arrayPtr << std::endl;
	std::cout << "The memory address for the array is " << &array << std::endl << std::endl;

	for (int i = 0; i < sizeof(array) / sizeof(int); ++i)
	{
		array[i] = i;

		std::cout << "The memory address of array[" << i << "] is " << &array[i] << std::endl;
		std::cout << "The memory address of arrayPtr + " << i << " is " << (arrayPtr + i) << std::endl << std::endl;

		std::cout << "The value of array[" << i << "] is " << array[i] << std::endl;
		std::cout << "The dereferenced value of arrayPtr + " << i << " is " << *(arrayPtr + i) << std::endl << std::endl;
	}

	return 0;
}