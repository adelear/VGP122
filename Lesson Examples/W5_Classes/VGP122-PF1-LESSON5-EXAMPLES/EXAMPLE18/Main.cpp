#include <iostream>

#include "Ship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"

int main()
{
	Ship* s = new Carrier(5);

	std::cout << "The carrier has a size of " << s->getSize() << " meters" << std::endl;

	delete s;

	std::cout << std::endl;

	s = new Cruiser(3);

	std::cout << "The cruiser has a size of " << s->getSize() << " meters" << std::endl;

	delete s;

	std::cout << std::endl;

	s = new Destroyer(3);

	std::cout << "The cruiser has a size of " << s->getSize() << " meters" << std::endl;

	delete s;

	return 0;
}