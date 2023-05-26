#pragma once

#include "Ship.h"
#include "ShipEngine.h"

class Carrier : public Ship, public ShipEngine
{
public:
	Carrier(int, int);
	~Carrier();

	int getSize() const;
	int getSpeed() const;
};