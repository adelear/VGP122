#include <iostream>

#include "Ship.h"

int main()
{
	Ship* s = new Ship(100);

	std::cout << "The size of the ship is " << s->getSize() << " meters" << std::endl;

	delete s;

	return 0;
}