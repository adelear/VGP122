#include <iostream>

#include "Complex.h"

using namespace std;

int main()
{
	Complex<int> c(1, 2);

	cout << "The complex number is " << c;

	return 0;
}