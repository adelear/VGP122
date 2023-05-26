#include "Carrier.h"

Carrier::Carrier(int s) : Ship(s)
{
	std::cout << "Carrier being created." << std::endl;
}

Carrier::~Carrier()
{
	std::cout << "Carrier being destroyed." << std::endl;
}

int Carrier::getSize() const
{
	return size;
}