#include <iostream>

#include "Base.h"
#include "Derived.h"

using namespace std;

int main()
{
	Base* b;
	Derived* d = new Derived();

	b = *&d;

	b->print();

	delete b;

	return 0;
}