#include "Carrier.h"

Carrier::Carrier(int s) : Ship(s)
{
	std::cout << "Carrier being created." << std::endl;
}

Carrier::Carrier(const Carrier& s) : Ship(s.size)
{
	std::cout << "Carrier being copied." << std::endl;
}

Carrier::~Carrier()
{
	std::cout << "Carrier being destroyed." << std::endl;
}