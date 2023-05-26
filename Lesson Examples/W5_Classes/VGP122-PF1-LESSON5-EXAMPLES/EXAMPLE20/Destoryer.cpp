#include "Destroyer.h"

Destroyer::Destroyer(int s)
{
	std::cout << "Destroyer being created." << std::endl;

	c = new Cruiser(s);
}

Destroyer::~Destroyer()
{
	std::cout << "Destroyer being destroyed." << std::endl;

	delete c;
}

int Destroyer::getSize() const
{
	return c->getSize();
}