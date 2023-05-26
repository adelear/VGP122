#include "Carrier.h"

Carrier::Carrier(int size, int speed) : Ship(size), ShipEngine(speed)
{
	std::cout << "Carrier being created." << std::endl;
}

Carrier::~Carrier()
{
	std::cout << "Carrier being destroyed." << std::endl;
}

int Carrier::getSize() const
{
	return this->size;
}

int Carrier::getSpeed() const
{
	return this->speed;
}