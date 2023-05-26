#include <iostream>

const char SUITS[] = { 'H', 'C', 'S', 'D' };
const char FACES[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

typedef struct card
{
	char face;
	char suit;
} Card;

typedef struct deck
{
	Card c[52];

	void init(Card*);
} Deck;

int main()
{
	Deck* d = new Deck;

	d->init(d->c);

	for (int i = 0; i < 52; ++i)
	{
		std::cout << (d->c[i]).face << (d->c[i]).suit << " ";
	}

	delete d;

	return 0;
}

void Deck::init(Card* card)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			card[(i * 13) + j].suit = SUITS[i];
			card[(i * 13) + j].face = FACES[j];
		}
	}
}