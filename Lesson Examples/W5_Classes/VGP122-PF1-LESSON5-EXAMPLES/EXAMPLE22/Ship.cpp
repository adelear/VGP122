#include "Ship.h"

Ship::~Ship()
{
	std::cout << "Ship being destroyed." << std::endl;

	delete size;
}