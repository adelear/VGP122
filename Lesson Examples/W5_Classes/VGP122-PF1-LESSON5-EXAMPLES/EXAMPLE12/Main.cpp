#include <iostream>

#include "Deck.h"
#include "Card.h"

int main()
{
	Deck* d = new Deck();

	d->showCards();

	delete d;

	return 0;
}