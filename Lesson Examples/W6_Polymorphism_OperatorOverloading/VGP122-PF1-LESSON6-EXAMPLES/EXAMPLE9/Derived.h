#pragma once

#include "Base.h"

class Derived : public Base
{
public:
	Derived();
	~Derived();

	void print() override;
};