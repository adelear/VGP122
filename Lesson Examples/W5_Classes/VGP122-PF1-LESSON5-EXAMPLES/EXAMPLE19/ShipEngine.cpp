#include "ShipEngine.h"

ShipEngine::ShipEngine(int s)
{
	this->speed = s;

	std::cout << "ShipEngine being created." << std::endl;
}

ShipEngine::~ShipEngine()
{
	std::cout << "ShipEngine being destroyed." << std::endl;
}

int ShipEngine::getSpeed() const
{
	return this->speed;
}