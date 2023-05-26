#include <iostream>

#include "Card.h"

int main()
{
	Card c;
	Card* cp = &c;

	c.face = 'A';
	c.suit = 'S';

	std::cout << "Card: " << c.face << c.suit << std::endl << std::endl;

	std::cout << cp << std::endl;
	std::cout << "Card: " << cp->face << cp->suit << std::endl;

	return 0;
}