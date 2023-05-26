#include <iostream>
#include <climits>

int main()
{
	int* p = new int;
	double* d = new double;
	char* c;

	*p = 65;
	c = reinterpret_cast<char*>(p);

	std::cout << "The value of the dereferenced int pointer is " << *p << std::endl;
	std::cout << "The value of the dereferenced char pointer is " << *c << std::endl << std::endl;

	std::cout << "The value of the int pointer is " << p << std::endl;
	std::cout << "The value of the char pointer is " << c << std::endl << std::endl;


	*d = DBL_MAX;
	p = reinterpret_cast<int*>(d);

	std::cout << "The value of the dereferenced int pointer is " << *p << std::endl;
	std::cout << "The value of the dereferenced double pointer is " << *d << std::endl << std::endl;

	std::cout << "The value of the int pointer is " << p << std::endl;
	std::cout << "The value of the double pointer is " << d << std::endl << std::endl;

	delete d;
	delete c;

	return 0;
}