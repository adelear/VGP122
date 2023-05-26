#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int i = 10;
	double d;
	float f;

	//Type casting from int to double
	d = (double)i;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	//Type casting from double to int
	d = DBL_MAX;
	i = (int)d;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	//Type casting from double to float
	f = (float)d;

	std::cout << "The value of f is " << f << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;


	d = 3.14159;
	i = (int)d;

	std::cout << "The value of i is " << i << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	f = (float)d;

	std::cout << "The value of f is " << f << std::endl;
	std::cout << "The value of d is " << d << std::endl << std::endl;

	return 0;
}