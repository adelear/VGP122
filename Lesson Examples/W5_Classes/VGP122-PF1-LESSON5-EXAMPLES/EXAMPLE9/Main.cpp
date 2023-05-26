#include <iostream>

#include "Card.h"

int main()
{
	Card* c1 = new Card();
	Card* c2 = new Card('A');
	Card* c3 = new Card('A', 'S');

	std::cout << "Card #1: " << c1->getFace() << c1->getSuit() << std::endl << std::endl;
	std::cout << "Card #2: " << c2->getFace() << c2->getSuit() << std::endl << std::endl;
	std::cout << "Card #3: " << c3->getFace() << c3->getSuit() << std::endl << std::endl;

	delete c1;
	delete c2;
	delete c3;

	return 0;
}