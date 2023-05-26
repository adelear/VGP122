#include "Destroyer.h"

Destroyer::Destroyer(int s) : Cruiser(s)
{
	std::cout << "Destroyer being created." << std::endl;
}

Destroyer::~Destroyer()
{
	std::cout << "Destroyer being destroyed." << std::endl;
}