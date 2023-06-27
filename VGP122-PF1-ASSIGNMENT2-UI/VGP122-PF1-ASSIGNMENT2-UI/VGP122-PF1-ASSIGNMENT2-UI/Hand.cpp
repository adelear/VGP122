#include "Hand.h"


Hand::Hand() : start(0,0), end(0,0) { 
	cards.reserve(53);
}

Hand::~Hand() {


}
int Hand::getTotalValue() {
	int count = 0;
	int aces = 0;
	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getFace() < 11) {
			count += cards[i]->getFace();
		}
		else if (cards[i]->getFace() == 14) {
			aces++;
			count += 11;
		}
		else {
			count += 10;
		}
		//get face value of card and add them up
		//if face value > 10, the value is still 10
	}

	// Check if the hand has aces and the count is greater than 21
	while (count > 21 && aces > 0) {
		count -= 10;
		aces--;
	}

	return count;
} 
void Hand::getCardFromDeck(Deck* deck) {
	cards.push_back(deck->drawCard());  
	sort(); 
}

void Hand::setPos(float x1, float y1, float x2, float y2) { 
	//cards at the index value, goes to position x nad y 
	//cards[index]->gotoPos(x1, y1);  
	start = { x1,y1 }; 
	end = { x2, y2 }; 
}

//every time u get or remove card, sort TODO
void Hand::sort() {
	if (cards.empty()) {
		return; 
	}

	if (cards.size() == 1) {
		cards[0]->gotoPos(start.x, start.y);
		return; 
	}

	//determine how the distance
	int distance = end.distance(start) / (cards.size() - 1); 
	for (int i = 0; i < cards.size(); i++) {

		//divide distance between start and end 
		cards[i]->gotoPos(start.x + distance*i, start.y); 
	}
}

void Hand::clearHand() {
	cards.clear();  
} 

int Hand::getSizeOfHand() {
	return cards.size();
}

bool Hand::hasSameFaceCards() {
	if (cards.size() < 2) {
		return false;  // Not enough cards to have two of the same face
	}

	Card* firstCard = cards[0];
	for (int i = 1; i < cards.size(); i++) {
		if (cards[i]->getFace() == firstCard->getFace()) {
			return true;  // Found two cards with the same face
		}
	}

	return false;  // No two cards with the same face found
}
 
void Hand::moveCard(Hand* destinationHand, int index)
{
	if (index >= 0 && index < cards.size())
	{
		Card* card = cards[index];  // Get the card to move
		destinationHand->cards.push_back(card);  // Add the card to the destination hand 
		cards.erase(cards.begin() + index);  // Remove the card from the current hand
		sort();  // Sort the current hand after removing the card 
	} 
}