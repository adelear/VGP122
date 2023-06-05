#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex* num1 = new Complex(1, 2);
	Complex* num2 = new Complex(3, 4);

	Complex* total;

	total = num1->add(num2);

	cout << "The addition of comlpex numbers (" << num1->getReal() << " + " << num1->getImaginary() 
		<< "i) + (" << num2->getReal() << " + " << num2->getImaginary() << "i) = (" 
		<< total->getReal() << " + " << total->getImaginary() << "i)";

	delete num1;
	delete num2;
	delete total;

	return 0;
}