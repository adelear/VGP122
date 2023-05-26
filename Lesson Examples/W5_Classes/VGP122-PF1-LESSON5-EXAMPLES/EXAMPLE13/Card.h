#pragma once

#include "Deck.h";

class Card
{
	friend class Deck;

public:
	char getSuit() const;
	char getFace() const;

	static const char SUITS[];
	static const char FACES[];

private:
	Card(char = 'A', char = 'S');

	char face;
	char suit;
};