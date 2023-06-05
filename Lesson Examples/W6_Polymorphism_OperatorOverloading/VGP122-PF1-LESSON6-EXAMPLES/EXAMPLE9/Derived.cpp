#include "Derived.h"

Derived::Derived()
{
	cout << "Derived constructor invoked" << endl;
}

Derived::~Derived()
{
	cout << "Derived destructor invoked" << endl;
}

void Derived::print()
{
	cout << "Derived print invoked" << endl;
}