#include <iostream>

#include "Ship.h"
#include "Carrier.h"

int main()
{
	Ship* s1 = new Carrier(5);

	std::cout << "The carrier has a size of " << s1->getSize() << " meters" << std::endl << std::endl;

	Ship* s2 = s1;

	std::cout << "The carrier copy has a size of " << s2->getSize() << " meters" << std::endl << std::endl;

	delete s1;

	return 0;
}