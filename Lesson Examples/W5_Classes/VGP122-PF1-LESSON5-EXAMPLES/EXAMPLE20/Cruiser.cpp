#include "Cruiser.h"

Cruiser::Cruiser(int s) : Ship(s)
{
	std::cout << "Cruiser being created." << std::endl;
}

Cruiser::~Cruiser()
{
	std::cout << "Cruiser being destroyed." << std::endl;
}

int Cruiser::getSize() const
{
	return this->size;
}