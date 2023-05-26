#include <iostream>

void swapByValue(int, int);
void swapByReference(int&, int&);
void swapByPointer(int*, int*);

int main()
{
	int i, j;

	std::cout << "Enter an integer: ";
	std::cin >> i;

	std::cout << "Enter another integer: ";
	std::cin >> j;

	swapByValue(i, j);

	std::cout << "After swapping, the value of i is " << i << " and the value of j is " << j << std::endl << std::endl;

	swapByReference(i, j);

	std::cout << "After swapping, the value of i is " << i << " and the value of j is " << j << std::endl << std::endl;

	swapByPointer(&i, &j);

	std::cout << "After swapping, the value of i is " << i << " and the value of j is " << j << std::endl << std::endl;

	return 0;
}

void swapByValue(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void swapByReference(int& x, int& y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void swapByPointer(int* x, int* y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}