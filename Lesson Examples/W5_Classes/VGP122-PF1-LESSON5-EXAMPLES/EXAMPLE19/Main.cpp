#include <iostream>

#include "Carrier.h"

int main()
{
	Carrier* s = new Carrier(3, 10);

	std::cout << "The carrier has a size of " << s->getSize() << " meters" << std::endl;
	std::cout << "The carrier has a speed of " << s->getSpeed() << " knots" << std::endl;

	delete s;

	return 0;
}