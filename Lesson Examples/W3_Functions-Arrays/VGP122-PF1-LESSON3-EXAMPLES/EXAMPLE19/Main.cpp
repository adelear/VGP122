#include <iostream>
#include <array>

void printArray(int[]);

int main()
{
	// Default initialization
	int a1[10];
	
	// Specific value initialization
	int a2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// Specific size and value initialization
	int a3[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	// Specific size with NULL initialization
	int a4[10] = {};

	// Memory set initialization
	int a5[10];
	memset(a5, 0, sizeof(a5));

	// Memory copy initialization
	int a6[10];
	memcpy(a6, a2, sizeof(a2));

	printArray(a1);
	printArray(a2);
	printArray(a3);
	printArray(a4);
	printArray(a5);
	printArray(a6);

	return 0;
}

void printArray(int a[])
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
}