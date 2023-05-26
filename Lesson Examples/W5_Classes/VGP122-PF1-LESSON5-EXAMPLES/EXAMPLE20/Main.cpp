#include <iostream>

#include "Ship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"

int main()
{
	Destroyer* s = new Destroyer(3);

	std::cout << "The cruiser has a size of " << s->getSize() << " meters" << std::endl;

	delete s;

	return 0;
}