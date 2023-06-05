#pragma once

#include <iostream>

using namespace std; 

class Base
{
public:
	Base();
	virtual ~Base() = 0;

	virtual void print() = 0;
};