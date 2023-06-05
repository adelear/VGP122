#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex* num1 = new Complex(1, 2);

	Complex* total;

	total = num1->add(3, 4);

	cout << "The addition of comlpex numbers (" << num1->getReal() << " + " << num1->getImaginary() 
		<< "i) + (3 + 4i) = (" << total->getReal() << " + " << total->getImaginary() << "i)";

	delete num1;
	delete total;

	return 0;
}