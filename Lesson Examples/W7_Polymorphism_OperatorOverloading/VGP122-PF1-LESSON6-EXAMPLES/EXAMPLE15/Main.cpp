#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex<int> num1(1, 2);
	Complex<int> num2(3, 4);
	
	Complex<double> num3(1.0, 2.0);
	Complex<double> num4(3.0, 4.0);

	Complex<int> totalI;
	Complex<double> totalD;

	cout << "num1 is ";
	num1.print();
	cout << endl << endl;

	cout << "num2 is ";
	num2.print();
	cout << endl << endl;

	totalI = num1 + num2;
	cout << "total is ";
	totalI.print();
	cout << endl << endl;


	cout << "num3 is ";
	num3.print();
	cout << endl << endl;

	cout << "num4 is ";
	num4.print();
	cout << endl << endl;

	totalD = num3 + num4;
	cout << "total is ";
	totalD.print();
	cout << endl << endl;


	return 0;
}