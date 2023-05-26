#include <iostream>

int main()
{
	int i = 10;
	int* p = nullptr;

	//Allocating memory to pointer p
	p = new int;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to is " << *p << std::endl << std::endl;

	//Assign the value of i to the dereferenced pointer
	*p = i;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to is " << *p << std::endl << std::endl;

	std::cout << "The address of i is " << &i << std::endl << std::endl;

	//Free allocated memory
	delete p;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;
	std::cout << "The value stored in the memory address p is pointing to is " << *p << std::endl << std::endl;

	p = nullptr;

	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;

	return 0;
}