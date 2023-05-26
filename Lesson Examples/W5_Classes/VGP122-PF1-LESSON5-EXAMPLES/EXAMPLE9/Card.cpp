#include "Card.h"

Card::Card(char f, char s) : face(f), suit(s)
{ }

char Card::getSuit()
{
	return suit;
}

char Card::getFace()
{
	return face;
}

const char Card::SUITS[] = "HCSD";
const char Card::FACES[] = "23456789TJQKA";