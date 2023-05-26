#include "Card.h"

Card::Card(char face, char suit)
{
	this->face = face;
	this->suit = suit;
}

char Card::getSuit() const
{
	return suit;
}

char Card::getFace() const
{
	return face;
}

const char Card::SUITS[] = "HCSD";
const char Card::FACES[] = "23456789TJQKA";