#include <iostream>

#include "Card.h"

int main()
{
	Card* c = new Card;

	std::cout << c << std::endl;
	std::cout << c->face << std::endl;
	std::cout << c->suit << std::endl;

	c->face = 'A';
	c->suit = 'S';

	std::cout << "Card: " << c->face << c->suit << std::endl;

	delete c;

	return 0;
}