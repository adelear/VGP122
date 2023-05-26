#pragma once

#include <iostream>

class Ship
{
public:
	Ship(int);
	~Ship();

	int getSize() const;

private:
	int size;
};
