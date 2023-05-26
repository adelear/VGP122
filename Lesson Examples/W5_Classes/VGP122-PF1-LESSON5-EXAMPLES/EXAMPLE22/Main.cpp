#include <iostream>

#include "Ship.h"
#include "Carrier.h"

int main()
{
	int* i = new int(5);
	Carrier* s1 = new Carrier(i);

	std::cout << "The carrier has a size of " << s1->getSize() << " meters" << std::endl << std::endl;

	Carrier* s2 = new Carrier(*s1);

	std::cout << "The carrier copy has a size of " << s2->getSize() << " meters" << std::endl << std::endl;

	delete s1;
	delete s2;

	return 0;
}