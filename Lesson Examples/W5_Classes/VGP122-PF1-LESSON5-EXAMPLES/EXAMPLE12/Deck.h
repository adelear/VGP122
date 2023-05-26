#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck();
	~Deck();

	void showCards() const;

private:
	Card** card;
};