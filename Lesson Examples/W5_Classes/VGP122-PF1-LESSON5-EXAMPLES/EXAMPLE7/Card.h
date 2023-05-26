#pragma once

#include <cstdlib>
#include <ctime>

class Card
{
public:
	Card(char, char);

	char getSuit();
	char getFace();

	char face;
	char suit;

	static const char SUITS[];
	static const char FACES[];
};