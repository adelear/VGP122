#include "Ship.h"

Ship::Ship(int s)
{
	this->size = s;

	std::cout << "Ship being created." << std::endl;
}

Ship::~Ship()
{
	std::cout << "Ship being destroyed." << std::endl;
}