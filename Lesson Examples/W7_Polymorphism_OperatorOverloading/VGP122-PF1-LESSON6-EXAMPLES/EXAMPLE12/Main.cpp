#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex num1(1, 2);

	cout << "num1 is ";
	num1.print();
	cout << endl << endl;

	++num1;
	cout << "Pre-increment of num1 is ";
	num1.print();
	cout << endl << endl;

	num1++;
	cout << "Post-increment of num1 is ";
	num1.print();
	cout << endl << endl;

	--num1;
	cout << "Pre-decrement of num1 is ";
	num1.print();
	cout << endl << endl;

	num1--;
	cout << "Post-decrement of num1 is ";
	num1.print();
	cout << endl << endl;

	return 0;
}