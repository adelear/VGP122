#include <iostream>

int main()
{
	int i = 10;
	int* p = &i;

	char c = 'a';
	char* cp = nullptr;

	float f = 0.0f;
	float* fp = nullptr;

	double d = 0.0;
	double* dp = nullptr;

	bool b = true;
	bool* bp = &b;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The address of variable i is " << &i << std::endl;
	std::cout << "The value of pointer p is " << p << std::endl;
	std::cout << "The address of pointer p is " << &p << std::endl;

	std::cout << "The value of i accessed indirectly through pointer p is " << *p << std::endl << std::endl;


	cp = &c;

	std::cout << "The value of c is " << (char)c << std::endl;
	std::cout << "The address of variable c is " << (void*)&c << std::endl;
	std::cout << "The value of pointer cp is " << (char)*cp << std::endl;
	std::cout << "The address of pointer cp is " << (void*)&cp << std::endl;

	std::cout << "The value of c accessed indirectly through pointer cp is " << *cp << std::endl << std::endl;


	fp = &f;

	std::cout << "The value of f is " << f << std::endl;
	std::cout << "The address of variable f is " << &f << std::endl;
	std::cout << "The value of pointer fp is " << fp << std::endl;
	std::cout << "The address of pointer fp is " << &fp << std::endl;

	std::cout << "The value of f accessed indirectly through pointer fp is " << *fp << std::endl << std::endl;


	dp = &d;

	std::cout << "The value of d is " << d << std::endl;
	std::cout << "The address of variable d is " << &d << std::endl;
	std::cout << "The value of pointer dp is " << dp << std::endl;
	std::cout << "The address of pointer dp is " << &dp << std::endl;

	std::cout << "The value of d accessed indirectly through pointer dp is " << *dp << std::endl << std::endl;


	bp = &b;

	std::cout << "The value of b is " << b << std::endl;
	std::cout << "The address of variable b is " << &b << std::endl;
	std::cout << "The value of pointer bp is " << bp << std::endl;
	std::cout << "The address of pointer bp is " << &bp << std::endl;

	std::cout << "The value of b accessed indirectly through pointer dp is " << *bp << std::endl << std::endl;

	return 0;
}