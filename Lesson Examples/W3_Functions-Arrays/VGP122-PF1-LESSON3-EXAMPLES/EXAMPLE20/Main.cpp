#include <iostream>
#include <cstdlib>
#include <ctime>

void bubbleSort(int[], const int);

int main()
{
	const int SIZE = 10;

	int array[SIZE];

	srand(time(0));

	for (int i = 0; i < SIZE; ++i)
	{
		array[i] = 1 + rand() % SIZE;
	}

	for (int x : array)
		std::cout << x << std::endl;

	std::cout << std::endl;

	bubbleSort(array, SIZE);

	for (int x : array)
		std::cout << x << std::endl;

	return 0;
}

void bubbleSort(int a[], const int SIZE)
{
	int temp;

	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				//Swap algorithm
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}