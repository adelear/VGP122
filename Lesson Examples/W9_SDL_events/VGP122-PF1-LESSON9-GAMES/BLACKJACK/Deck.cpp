#include "Deck.h"

Deck::Deck()
{
	cards.reserve(NUMCARDS);

	createCards();
	shuffle();
	layout();
}

Deck::~Deck()
{
	for (int i = 0; i < cards.size(); ++i)
		delete cards[i];
}

void Deck::update()
{
	std::vector<Card*>::iterator it = cards.begin();

	while (it != cards.end())
	{
		(*it)->update();

		++it;
	}
}

void Deck::render()
{
	std::vector<Card*>::iterator it = cards.begin();

	while (it != cards.end())
	{
		(*it)->render();

		++it;
	}
}

Card* Deck::getCardAt(int index)
{
	return cards[index];
}

void Deck::createCards()
{
	for (int i = 0; i < NUMCARDS / 2; ++i)
	{
		int rndCard = 0 + rand() % (52 - 0 + 1);
		cards.push_back(new Card("images/cards.png", 0, 0, 44, 64, 1, 12, rndCard));
		cards.push_back(new Card("images/cards.png", 0, 0, 44, 64, 1, 12, rndCard));
	}
}

void Deck::layout()
{
	for (int i = 0; i < NUMCARDS; ++i)
	{
		for (int j = 0; j < NUMCARDS; ++j)
		{
			float x = 110 + (50 * j);
			float y = 100 + (75 * i);
			cards[j + (NUMCARDS * i)]->position = { x, y };
		}
	}
}

void Deck::shuffle()
{
	for (int i = 0; i < cards.size(); ++i)
	{
		int rndCard = rand() % NUMCARDS;
		Card* temp = cards[rndCard];
		cards[rndCard] = cards[i];
		cards[i] = temp;
	}
}