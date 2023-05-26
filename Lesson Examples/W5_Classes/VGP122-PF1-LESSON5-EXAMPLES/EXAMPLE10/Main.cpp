#include <iostream>

#include "Card.h"

using namespace std;

int main()
{
	Card* c = new Card();

	cout << "Card: " << c->getFace() << c->getSuit() << endl << endl;

	delete c;

	return 0;
}