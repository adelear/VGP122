#include <iostream>

int main()
{
	const int SIZE_OF_ARRAY = 10;

	int* arrayPtr = (int*)calloc(SIZE_OF_ARRAY, sizeof(int));

	for (int i = 0; i < SIZE_OF_ARRAY; ++i)
	{
		arrayPtr[i] = i;

		std::cout << "The value of array[" << i << "] is " << arrayPtr[i] << std::endl;
	}

	free(arrayPtr);

	return 0;
}