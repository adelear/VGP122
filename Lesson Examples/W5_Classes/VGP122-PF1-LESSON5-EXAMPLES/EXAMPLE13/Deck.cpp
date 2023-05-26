#include "Deck.h"

Deck::Deck()
{
	card = new Card*[52];

	srand(time(0));

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			card[i * 13 + j] = new Card(Card::FACES[j], Card::SUITS[i]);
		}
	}
}

Deck::~Deck()
{
	for (int i = 0; i < 52; ++i)
	{
		delete card[i];
	}

	delete[] card;
}

void Deck::showCards() const
{
	for (int i = 0; i < 52; ++i)
	{
		cout << card[i]->getFace() << card[i]->getSuit() << " ";
	}
}