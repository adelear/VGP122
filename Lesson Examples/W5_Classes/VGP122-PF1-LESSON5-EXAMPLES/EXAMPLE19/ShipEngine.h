#pragma once

#include <iostream>

class ShipEngine
{
public:
	ShipEngine(int);
	virtual ~ShipEngine();

	virtual int getSpeed() const = 0;

protected:
	int speed;
};