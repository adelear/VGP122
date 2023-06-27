#pragma once

#include <vector>
#include <unordered_set>

#include "GameObject.h"
#include "Game.h"
#include "Card.h"

class Deck : public GameObject
{
public:
	Deck();
	~Deck();

	void update();
	void render();

	Card* drawCard();  
	void createCard();
	void shuffle();
	void layout();
	void resetDeck(); 

private:
	std::vector<Card*> cards;
	int index;
};