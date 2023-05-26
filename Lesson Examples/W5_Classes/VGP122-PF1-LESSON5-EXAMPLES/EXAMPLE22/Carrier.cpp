#include "Carrier.h"

Carrier::Carrier(int* s)
{
	std::cout << "Carrier being created." << std::endl;

	this->size = new int(*s);
}

Carrier::Carrier(const Carrier& s)
{
	std::cout << "Carrier being copied." << std::endl;

	this->deepCopy(s);
}

Carrier::~Carrier()
{
	std::cout << "Carrier being destroyed." << std::endl;
}

void Carrier::deepCopy(const Carrier& s)
{
	this->size = new int(*s.size);
}

int Carrier::getSize() const
{
	return *this->size;
}