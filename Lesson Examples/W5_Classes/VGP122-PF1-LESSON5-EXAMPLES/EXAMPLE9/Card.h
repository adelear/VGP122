#pragma once

#include <cstdlib>
#include <ctime>

using namespace std;

class Card
{
public:
	Card(char = 'A', char = 'S');

	char getSuit();
	char getFace();

	char face;
	char suit;

	static const char SUITS[];
	static const char FACES[];
};