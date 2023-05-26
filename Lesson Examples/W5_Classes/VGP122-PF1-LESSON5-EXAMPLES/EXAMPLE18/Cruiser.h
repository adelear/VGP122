#pragma once

#include "Ship.h"

class Cruiser : public Ship
{
public:
	Cruiser(int);
	~Cruiser();

	int getSize() const;
};