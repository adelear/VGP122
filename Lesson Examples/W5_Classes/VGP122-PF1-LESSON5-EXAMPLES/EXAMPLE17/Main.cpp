#include <iostream>

#include "Ship.h"
#include "Carrier.h"

int main()
{
	Ship* s = new Carrier(5);

	std::cout << "The carrier has a size of " << s->getSize() << " meters" << std::endl;

	delete s;

	return 0;
}