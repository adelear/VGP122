#pragma once

#include <iostream>

#include "Ship.h"

class Carrier : public Ship
{
public:
	Carrier(int*);
	Carrier(const Carrier&);

	~Carrier();

	int getSize() const;

private:
	void deepCopy(const Carrier&);
};