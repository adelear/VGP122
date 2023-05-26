#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex* num1 = new Complex(1, 2);
	Complex* num2 = new Complex(3, 4);
	Complex* total;

	total = num1->add(num2);
	cout << "The addition of comlpex numbers is ";
	total->print();
	cout << endl << endl;

	total = num1->subtract(num2);
	cout << "The subtraction of comlpex numbers is ";
	total->print();
	cout << endl << endl;

	total = num1->multiply(num2);
	cout << "The multiplication of comlpex numbers is ";
	total->print();
	cout << endl << endl;

	total = num1->divide(num2);
	cout << "The division of comlpex numbers is ";
	total->print();
	cout << endl << endl;

	delete num1;

	num1 = num2;
	cout << "num1 is ";
	num1->print();
	cout << endl << endl;

	delete num2;
	delete total;

	return 0;
}