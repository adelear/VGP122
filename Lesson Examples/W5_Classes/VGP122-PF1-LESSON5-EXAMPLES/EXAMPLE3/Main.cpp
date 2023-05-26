#include <iostream>

#include "Card.h"

int main()
{
	Card* c = new Card;

	c->face = Card::FACES[12];
	c->suit = Card::SUITS[2];

	std::cout << "Card: " << c->face << c->suit << std::endl;

	delete c;

	return 0;
}