#include "Card.h"

Card::Card()
{
	srand(time(0));

	face = FACES[rand() % 13];
	suit = SUITS[rand() % 4];
}

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