#pragma once

#include "Cruiser.h"

class Destroyer
{
public:
	Destroyer(int);
	~Destroyer();

	int getSize() const;

private:
	Cruiser* c;
};