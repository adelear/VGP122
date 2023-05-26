#pragma once

#include <cstdlib>
#include <ctime>

class Card
{
public:
	Card()
	{
		srand(time(0));

		face = FACES[rand() % 13];
		suit = SUITS[rand() % 4];
	}

	char getSuit()
	{
		return suit;
	}

	char getFace()
	{
		return face;
	}

	char face;
	char suit;

	static const char SUITS[];
	static const char FACES[];
};

const char Card::SUITS[] = "HCSD";
const char Card::FACES[] = "23456789TJQKA";