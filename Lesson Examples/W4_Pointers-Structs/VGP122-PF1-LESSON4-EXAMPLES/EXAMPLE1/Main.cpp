#include <iostream>

int main()
{
	int i = 10;
	char c = 'a';
	float f = 0.0f;
	double d = 0.0;
	bool b = true;

	std::cout << "i is stored at memory address " << &i << std::endl;
	std::cout << "i is " << sizeof(i) << " bytes" << std::endl;

	std::cout << "c is stored at memory address " << &c << std::endl;
	std::cout << "c is " << sizeof(c) << " bytes" << std::endl;

	std::cout << "f is stored at memory address " << &f << std::endl;
	std::cout << "f is " << sizeof(f) << " bytes" << std::endl;

	std::cout << "d is stored at memory address " << &d << std::endl;
	std::cout << "d is " << sizeof(d) << " bytes" << std::endl;

	std::cout << "b is stored at memory address " << &b << std::endl;
	std::cout << "b is " << sizeof(b) << " bytes" << std::endl;

	return 0;
}