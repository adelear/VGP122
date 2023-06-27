#pragma once

#include "Global.h"

#include "Game.h"
#include "Card.h"
#include "Deck.h"
#include "Sprite.h"
#include <cstdlib>
#include <ctime>
#include <vector>  

class Hand {
	public:
		Hand();
		~Hand(); 
		int getTotalValue(); 
		void getCardFromDeck(Deck* deck); 
		void setPos(float x1, float y1, float x2, float y2);
		void sort(); 
		void clearHand(); 
		int getSizeOfHand(); 
		bool hasSameFaceCards(); 
		void moveCard(Hand* destinationHand, int index); 

	private:
		std::vector<Card*> cards;
		Vector2D start;
		Vector2D end;
}; 

