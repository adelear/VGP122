#include <iostream>
#include <cstdlib>

int main()
{
	int i = 10;
	int* p = nullptr;

	//Allocating memory to pointer p
	p = (int*)malloc(sizeof(int));

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to " << *p << std::endl << std::endl;

	//Assigning a value to the dereferenced pointer
	*p = i;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to " << *p << std::endl << std::endl;

	std::cout << "The address of i is " << &i << std::endl << std::endl;

	//Freeing allocated memory 
	free(p);

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to " << *p << std::endl << std::endl;

	p = nullptr;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl << std::endl;

	//Allocating new memory to pointer
	p = (int*)malloc(sizeof(int));

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to " << *p << std::endl << std::endl;

	free(p);
	p = nullptr;

	return 0;
}