#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex num1(1, 2);
	Complex num2(3, 4);

	cout << "num1 is ";
	num1.print();
	cout << endl << endl;

	cout << "num2 is ";
	num1.print();
	cout << endl << endl;

	cout << "num1 == num2 is " << (num1 == num2) << endl << endl;
	cout << "num1 != num2 is " << (num1 != num2) << endl << endl;
	cout << "num1 > num2 is " << (num1 > num2) << endl << endl;
	cout << "num1 < num2 is " << (num1 < num2) << endl << endl;
	cout << "num1 >= num2 is " << (num1 >= num2) << endl << endl;
	cout << "num1 <= num2 is " << (num1 <= num2) << endl << endl;

	return 0;
}