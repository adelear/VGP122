#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int> x(new int);
	std::shared_ptr<int[]> array(new int[10]);

	*x = 10;

	std::shared_ptr<int> xCopy = x;

	for (int i = 0; i < 10; ++i)
	{
		array[i] = i;
	}

	std::cout << "The memory address of x is " << &x << std::endl;
	std::cout << "The dereferenced value of x is " << *x << std::endl << std::endl;
	std::cout << "The memory address of y is " << &xCopy << std::endl;
	std::cout << "The dereferenced value of y is " << *xCopy << std::endl << std::endl;

	std::cout << "The number of references pointing to array is " << array.use_count() << std::endl << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "The memory address of x is " << &array[i] << std::endl;
		std::cout << "The dereferenced value of x is " << array[i] << std::endl << std::endl;
	}

	std::shared_ptr<int[]> arrayCopy = array;

	std::cout << "The number of references pointing to array is " << array.use_count() << std::endl << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "The memory address of x is " << &arrayCopy[i] << std::endl;
		std::cout << "The dereferenced value of x is " << arrayCopy[i] << std::endl << std::endl;
	}

	return 0;
}