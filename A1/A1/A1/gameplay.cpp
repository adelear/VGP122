#include "gameplay.h"

// Deal the player a new card
void hitTurn(string* playerHand, int& handSize, string* playerSuit, bool player) {
	string newCard = randomCard(player);
	string newSuit = randomSuit();
	cout << "\nHit! New card: " << newCard << " " << newSuit << endl;
	addCard(playerHand, playerSuit, handSize, newCard, newSuit);
	cout << "Card Count: " << cardCount(playerHand, handSize) << endl;
}

// Hold your total and end your turn 
void standTurn() {
	cout << "Stand!" << endl;
}

void splitTurn(bool equalCards, string* playerHand, string* playerSuit, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int betPlaced) {
	//Once player chooses to split, hasSplit = true
	// when players Hit, hasSplit will add cards onto both decks
	// Also, there will be two bets. So players can lose the bet twice, win once, but lose once, or win twice 

	hasSplit = true;
	secondHand[0] = playerHand[1];
	secondSuit[0] = playerSuit[1];
	secondHand[1] = randomCard(true);
	secondSuit[1] = randomSuit();
	playerHand[1] = randomCard(true);
	playerSuit[1] = randomSuit();

	cout << "-----------------------------------------------------------" << endl;
	cout << "SPLITTING" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "First hand: " << playerHand[0] << " " << playerSuit[0] << " | " << playerHand[1] << " " << playerSuit[1] << endl;
	cout << "Second hand: " << secondHand[0] << " " << secondSuit[0] << " | " << secondHand[1] << " " << secondSuit[1] << endl;
}

void doubleDown(int& betPlaced, string* playerHand, string* playerSuit, int& handSize, bool& doubledDown) {
	cout << "-----------------------------------------------------------" << endl;
	cout << "Double Down!" << endl;
	cout << "-----------------------------------------------------------" << endl;
	doubledDown = true;
	betPlaced *= 2;
	cout << "New Bet: " << betPlaced << endl;

	playerHand[2] = randomCard(true);
	playerSuit[2] = randomSuit();
	cout << "New Card: " << playerHand[2] << " " << playerSuit[2] << endl;
	handSize++;
}

void passTurn() {
	cout << "Passed Turn!" << endl;
}

int cardCount(string cardArray[], int arraySize) {

	int count = 0;
	for (int i = 0; i < arraySize; i++) {
		if (cardArray[i] == "ACE 1") {
			count += 1;
		}
		else if (cardArray[i] == "ACE 11") {
			count += 11;
		}
		else if (cardArray[i] == "10" || cardArray[i] == "Jack" || cardArray[i] == "Queen" || cardArray[i] == "King") {
			count += 10;
		}
		else {
			for (int j = 2; j < 10; j++) {
				if (cardArray[i] == to_string(j)) {
					count += j;
					break;
				}
			}
		}
	}
	return count;
}

// Returns the suit of a card, for aesthetics 
string randomSuit() {
	int suit = rand() % 4 + 1;

	if (suit == 1) {
		return "OF HEARTS";
	}

	if (suit == 2) {
		return "OF SPADES";
	}
	if (suit == 3) {
		return "OF CLUBS";
	}
	if (suit == 4) {
		return "OF DIAMONDS";
	}
	return " ";  
}

//adds a card into the player's hand
int addCard(string* hand, string* suit, int& cardCount, string card, string cardSuit) {
	hand[cardCount] = card;
	suit[cardCount] = cardSuit;
	cardCount++;
	return cardCount; 
}

//Generates and returns a random card 
string randomCard(bool player, string* hand, string* suit, int cardCount) {
	//TODO (the same card and suit cannot exist multiple times in the game) 
	int card = rand() % 13 + 1;

	if (card == 1) {
		if (player == true) {
			bool validInput = false;
			cout << "\nCard: Ace 1 OR 11: ";


			while (!validInput) {
				int userInput;
				cin >> userInput;

				if (userInput == 1) { // ACE
					validInput = true;
					return "ACE 1";

				}
				else if (userInput == 11) {
					validInput = true;
					return "ACE 11";

				}
				else {
					cout << "\nEnter 1 or 11" << endl;
				}
			}
		}
		else if (player == false) {
			/*
			* if ((add up dealer count) + 11 > 21{
			*	return "ACE 1" 
			* 
			* else{ 
			* 
			* return "ACE 11" 
			
			
			*/
			int randomNum = rand() % 2 + 1;
			//Dealer picks 11 only if it doesnt go over 
			if (randomNum == 1) {
				return "ACE 1";
			}
			else {
				return "ACE 11";
			}
		}
	}

	else if (card > 1 && card < 11) { // CARDS 2 TO 10
		return to_string(card);
	}
	else if (card == 11) { // JACK
		return "Jack";
	}
	else if (card == 12) { // QUEEN
		return "Queen";
	}
	else if (card == 13) { // KING
		return "King";
	}
	// Default return statement
	return "";
}

void playerMenu(string playerChoice, string* playerHand, string* playerSuit, int& handSize, bool& done, bool hasEqualCards, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int& betPlaced, int& secondSize, bool& doubledDown) {
	if (playerChoice == "H") {
		hitTurn(playerHand, handSize, playerSuit, true);
	}
	if (playerChoice == "S") {
		standTurn();
		done = true;
	}
	if (playerChoice == "SP") {
		if (hasSplit == true) {
			cout << "-----------------------------------------------------------" << endl;
			cout << "You have already split your hand." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		else if (hasEqualCards == true) {
			hasSplit = true;
			splitTurn(hasEqualCards, playerHand, playerSuit, secondHand, secondSuit, hasSplit, totalBet, betPlaced);
		}
		else {
			cout << "-----------------------------------------------------------" << endl;
			cout << "Split cannot be done. Your cards are not the same." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
	}
	if (playerChoice == "D") {
		if (handSize == 2) {
			int handCount = cardCount(playerHand, handSize);
			if ((handCount == 9) || (handCount == 10) || (handCount == 11)) {
				if ((betPlaced * 2) > totalBet) {
					cout << "-----------------------------------------------------------" << endl;
					cout << "Cannot Double Bet." << endl;
					cout << "-----------------------------------------------------------" << endl;
				}
				else {
					doubleDown(betPlaced, playerHand, playerSuit, handSize, doubledDown);
					done = true;
				}
			}
			else {
				cout << "-----------------------------------------------------------" << endl;
				cout << "Hand does not total 9, 10, or 11." << endl;
				cout << "-----------------------------------------------------------" << endl;
			}
		}
		else {
			cout << "-----------------------------------------------------------" << endl;
			cout << "Double Down can only be used when you have 2 cards in your hand" << endl;
			cout << "that total up to 9, 10, or 11" << endl;
			cout << "-----------------------------------------------------------" << endl;
		}

	}
	if (playerChoice == "X") {
		passTurn();
		done = true;
	}
}
//Printing our playerHand 
void printBoard(string playerHand[], string playerSuit[], int handSize) {
	cout << "-----------------------------------------------------------" << endl;
	cout << "Cards: ";
	for (int i = 0; i < handSize; i++) {
		cout << playerHand[i] << " " << playerSuit[i];
		if (i != handSize - 1) { // add separator unless it's the last card
			cout << "| ";
		}
	}
	cout << "\nCard Count: " << cardCount(playerHand, handSize) << endl;
}

void winLoseConditions(string playerHand[], int handSize, string dealerHand[], int dealerSize, int& totalBet, int betPlaced, bool& gameRunning) {
	// WIN CONDITIONS: IF PLAYER HAS MORE CARD COUNT THAN DEALER BUT LESS THAN 22 AND IF DEALER HAS > 21 
	if ((cardCount(playerHand, handSize) > cardCount(dealerHand, dealerSize)) && (cardCount(playerHand, handSize) <= 21)) {
		cout << "\nYou win!" << endl;
		totalBet += betPlaced;
		cout << "\nBalance: " << totalBet << endl;
	}

	else if (cardCount(dealerHand, dealerSize) > 21 && cardCount(playerHand, handSize) < 22) {
		cout << "\nDealer busts. YOU WIN!" << endl;
		totalBet += betPlaced;
		cout << "\nBalance: " << totalBet << endl;
	}

	//LOSE CONDITIONS -> if card count is over 21 
	else if (cardCount(playerHand, handSize) > 21) {
		cout << "\nCard Count over 21. YOU LOSE" << endl;
		totalBet -= betPlaced;
		cout << "\nBalance: " << totalBet << endl;
	}

	//If dealer is closer to 21, but not over 21, you lose
	else if ((cardCount(playerHand, handSize) < cardCount(dealerHand, dealerSize)) && (cardCount(dealerHand, dealerSize) < 22)) {
		cout << "\nDealer closer to 21. YOU LOSE" << endl;
		totalBet -= betPlaced;
		cout << "\nBalance: " << totalBet << endl;
	}

	//DRAW CONDITIONS 
	else if (cardCount(playerHand, handSize) == cardCount(dealerHand, dealerSize)) {
		cout << "\nDraw!" << endl;
		cout << "Balance: " << totalBet;
	}
	else {
		cout << "\nThe game has ended." << endl;
	}

	//LOSE CONDITIONS -> lost all bet money 
	if (totalBet <= 0) {
		cout << "\nYou lost all your money!" << endl;
		gameRunning = false;
	}
}

// Asking user to play again  
void playAgain(bool& gameRunning, int totalBet) {
	if (totalBet > 0) {
		cout << "\nPlay again? Y/N: ";
		string choice;
		cin >> choice;

		if (choice == "Y") {
			gameRunning = true;
		}
		else if (choice == "N") {
			gameRunning = false;
		}
	}
}

//Print out the balance
void printBalance(int totalBet) {
	cout << "Balance is " << totalBet << endl;
}