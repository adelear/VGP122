#include <iostream>

int main()
{
	const int SIZE = 10;

	int i;
	int array[SIZE];

	for (i = 0; i < SIZE; ++i)
		array[i] = 0;

	for (i = 0; i < SIZE; ++i)
		std::cout << "array[" << i << "] = " << array[i] << std::endl;

	return 0;
}