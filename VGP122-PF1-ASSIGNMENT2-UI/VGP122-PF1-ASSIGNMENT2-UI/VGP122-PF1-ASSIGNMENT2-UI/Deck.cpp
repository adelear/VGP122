#include "Deck.h"

Deck::Deck()
{
	cards.reserve(53);  

	createCard();
	shuffle();
	layout();
}

Deck::~Deck()
{
	for (Card* ptr : cards) { 
		delete ptr; 
		ptr = nullptr; 
	}
	cards.clear(); 
}

void Deck::update()
{
	for (Card* ptr : cards) { 
		ptr->update(); 
	}
}

void Deck::render()
{
	for (Card* ptr : cards) {
		ptr->render(); 
	}
}

void Deck::createCard()
{
	for (int i = 0; i < 52; i++) { 
		int face = (i % 13) + 2; 
		int suit = (i / 13); 
		Card* card = new Card("images/cards.png", 0, 0, 225, 319, 6, 9, 0, 0, face, suit); 
		cards.push_back(card); 
		card->setVisible(false); 
		card->setCurrentFrame(i + 2); 
	}
}

void Deck::shuffle() {
	index = 0; 
	for (long long unsigned i = 0; i < cards.size(); i++) {
		std::swap(cards[i], cards[rand() % cards.size()]);    
	}
}

void Deck::layout()
{
	//wha
}


Card* Deck::drawCard()     
{
	// Assuming the deck is implemented as a vector of Card pointers named "cards"
	if (cards.empty())
		return nullptr; // Return nullptr if the deck is empty

	Card* drawnCard = cards[index]; // Get the last card from the deck 
	drawnCard->setVisible(true); 
	//cards.pop_back(); // Remove the drawn card from the deck
	index++; 
	return drawnCard;
}

void Deck::resetDeck()
{
	// Clear the deck vector
	for (Card* card : cards)
	{
		delete card;
	}
	cards.clear();

	// Repopulate the deck with all the cards
	createCard(); 
	shuffle(); 
} 
