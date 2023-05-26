#pragma once

#include <iostream>

class Ship
{
public:
	Ship(int);
	~Ship();

	virtual int getSize() const = 0;

private:
	int size;
};
