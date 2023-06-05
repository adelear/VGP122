#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Number* num1 = new Complex(1, 2);

	Complex* total;

	total = (Complex*)num1->add(3, 4);

	cout << "The addition of comlpex numbers (" << ((Complex*)num1)->getReal() << " + " << ((Complex*)num1)->getImaginary()
		<< "i) + (3 + 4i) = (" << total->getReal() << " + " << total->getImaginary() << "i)";

	delete num1;
	delete total;

	return 0;
}