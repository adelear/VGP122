#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex num1(1, 2);
	Complex num2(3, 4);
	Complex total;

	num1 += num2;
	cout << "The addition of num1 and num2 is ";
	num1.print();
	cout << endl << endl;

	num1 -= num2;
	cout << "The subtraction of num1 and num2 is ";
	num1.print();
	cout << endl << endl;

	num1 *= num2;
	cout << "The multiplication of num1 and num2 is ";
	num1.print();
	cout << endl << endl;

	num1 /= num2;
	cout << "The division of num1 and num2 is ";
	num1.print();
	cout << endl << endl;

	return 0;
}