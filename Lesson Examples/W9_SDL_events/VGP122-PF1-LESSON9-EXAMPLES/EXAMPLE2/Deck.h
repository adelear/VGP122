#pragma once

#include <vector>
#include <iostream>
#include <sstream>

#include "Global.h"
#include "Game.h"
#include "GameObject.h"
#include "Card.h"

class Deck : public GameObject
{
public:
	Deck();
	~Deck();

	void update();
	void render();
	
	Deck* clone();

	Card* getCardAt(int);

	void createCards();
	void layout();
	void shuffle();

	std::vector<Card*> cards;
};