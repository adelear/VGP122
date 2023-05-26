#pragma once

#include <cstdlib>
#include <ctime>

using namespace std;

class Card
{
public:
	Card(char = 'A', char = 'S');

	char getSuit() const;
	char getFace() const;

private:
	char face;
	char suit;

	static const char SUITS[];
	static const char FACES[];
};