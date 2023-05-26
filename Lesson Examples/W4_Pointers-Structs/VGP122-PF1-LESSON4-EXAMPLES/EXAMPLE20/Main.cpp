#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> x (new int);
	std::unique_ptr<int[]> array(new int[10]);

	*x = 10;

	for (int i = 0; i < 10; ++i)
	{
		array[i] = i;
	}

	std::cout << "The memory address of x is " << &x << std::endl;
	std::cout << "The dereferenced value of x is " << *x << std::endl << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "The memory address of x is " << &array[i] << std::endl;
		std::cout << "The dereferenced value of x is " << array[i] << std::endl << std::endl;
	}

	return 0;
}