#pragma once

#include <iostream>

class Ship
{
public:
	Ship(int);
	virtual ~Ship();

	virtual int getSize() const;

protected:
	int size;
};
