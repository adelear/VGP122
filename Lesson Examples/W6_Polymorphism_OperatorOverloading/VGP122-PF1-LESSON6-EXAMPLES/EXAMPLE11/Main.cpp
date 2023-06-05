#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex num1(1, 2);
	Complex num2(3, 4);
	Complex total;

	total = num1 + num2;
	cout << "The addition of num1 and num2 is ";
	total.print();
	cout << endl << endl;

	total = num1 - num2;
	cout << "The subtraction of num1 and num2 is ";
	total.print();
	cout << endl << endl;

	total = num1 * num2;
	cout << "The multiplication of num1 and num2 is ";
	total.print();
	cout << endl << endl;

	total = num1 / num2;
	cout << "The division of num1 and num2 is ";
	total.print();
	cout << endl << endl;

	total = num1 * num2 + num2;
	cout << "The expression calculation of num1 and num2 is ";
	total.print();
	cout << endl << endl;

	return 0;
}