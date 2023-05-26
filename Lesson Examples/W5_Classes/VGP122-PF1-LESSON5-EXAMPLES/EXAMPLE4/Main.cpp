#include <iostream>

#include "Card.h"

int main()
{
	Card* c = new Card;

	c->setCard();

	std::cout << "Card: " << c->getFace() << c->getSuit() << std::endl;

	delete c;

	return 0;
}