#include <iostream>

int main()
{
	const int SIZE_OF_ARRAY = 10;

	int* array = new int[SIZE_OF_ARRAY];
	const char* word = "Hello World";

	for (int i = 0; i < SIZE_OF_ARRAY; ++i)
	{
		array[i] = i;

		std::cout << "The value of array [" << i << "] is " << array[i] << std::endl;
	}

	std::cout << word << std::endl;

	word = "Goodbye";

	std::cout << word << std::endl;

	delete[] array;

	return 0;
}