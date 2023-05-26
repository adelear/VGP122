#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int i = 10;
	double d;
	float f;

	//Implicit type conversion from int to double
	d = i;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	//Implicit type conversion from double to int
	d = DBL_MAX;
	i = d;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	//Implicit type conversion from double to float
	f = d;

	std::cout << "The value of f is " << f << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;


	d = 3.14159;
	i = d;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	f = d;

	std::cout << "The value of f is " << f << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	return 0;
}