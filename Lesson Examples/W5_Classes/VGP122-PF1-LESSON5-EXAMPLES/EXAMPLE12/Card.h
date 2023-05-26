#pragma once

class Card
{
public:
	Card(char = 'A', char = 'S');

	char getSuit() const;
	char getFace() const;

	static const char SUITS[];
	static const char FACES[];

private:
	char face;
	char suit;
};