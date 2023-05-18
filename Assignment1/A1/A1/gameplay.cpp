#include "gameplay.h"

// Deal the player a new card
void hitTurn(string* playerHand, int& handSize, string* playerSuit, bool player) { 
	string newSuit = randomSuit(handSize, playerSuit, playerHand); 
	string newCard = randomCard(player, playerHand, handSize, playerSuit);  
	cout << "\nHit! New card: " << newCard << " " << newSuit << endl;
	addCard(playerHand, playerSuit, handSize, newCard, newSuit);
	cout << "Card Count: " << cardCount(playerHand, handSize) << endl;
}

// Hold your total and end your turn 
void standTurn() {
	cout << "Stand!" << endl;
}

void splitTurn(bool equalCards, string* playerHand, string* playerSuit, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int betPlaced, int& handSize) {
	//Once player chooses to split, hasSplit = true
	// when players Hit, hasSplit will add cards onto both decks
	// Also, there will be two bets. So players can lose the bet twice, win once, but lose once, or win twice 

	hasSplit = true;
	secondHand[0] = playerHand[1]; 
	secondSuit[0] = playerSuit[1];
	secondSuit[1] = randomSuit(handSize, playerSuit, playerHand);  
	secondHand[1] = randomCard(true, playerHand, handSize, playerSuit);   
	playerSuit[1] = randomSuit(handSize, playerSuit, playerHand); 
	playerHand[1] = randomCard(true, playerHand, handSize, playerSuit); 
	 
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

	 
	playerSuit[2] = randomSuit(handSize, playerSuit, playerHand);
	playerHand[2] = randomCard(true, playerHand, handSize, playerSuit); 
	cout << "New Card: " << playerHand[2] << " " << playerSuit[2] << endl;
	handSize++;
}

void passTurn(bool& hasPassed) {
	cout << "Passed Turn!" << endl;
	hasPassed = true;   
}

int cardCount(string cardArray[], int arraySize) {
	//Adds up th total amount of the cards in a hand
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
string randomSuit(int& handSize, string* playerSuit, string* card) { 
    int suit = rand() % 4 + 1;
    string assignSuit; 
	 
    if (suit == 1) {
        assignSuit = "OF HEARTS"; 
    }

    if (suit == 2) {
        assignSuit = "OF SPADES"; 
    }
    if (suit == 3) {
        assignSuit = "OF CLUBS"; 
    }
    if (suit == 4) {
        assignSuit = "OF DIAMONDS"; 
    }
    return assignSuit;  
}
 

//adds a card into the player's hand
int addCard(string* hand, string* suit, int& cardCount, string card, string cardSuit) {
	hand[cardCount] = card;
	suit[cardCount] = cardSuit;
	cardCount++;
	return cardCount; 
}

//Generates and returns a random card 
string randomCard(bool player, string* hand, int& handSize, string* suit) { 
	//TODO (the same card and suit cannot exist multiple times in the game) 
	const int maxRecursionDepth = 10; 
	int recursionDepth = 0;
	string cardAssign; 

	while (recursionDepth < maxRecursionDepth) { 
		int card = rand() % 13 + 1;
		bool validCard = true;

		if (card == 1) {
			if (player == true) {
				bool validInput = false;
				cout << "\nCard: Ace 1 OR 11: ";


				while (!validInput) {
					int userInput;
					cin >> userInput;

					if (userInput == 1) { // ACE
						validInput = true;
						cardAssign = "ACE 1";

					}
					else if (userInput == 11) {
						validInput = true;
						cardAssign = "ACE 11";

					}
					else {
						cout << "\nEnter 1 or 11" << endl;
					}
				}
			}
			else if (player == false) {
				int cardNum = cardCount(hand, handSize) + 11;
				//When the dealer plays an ACE, it checks their card count. If adding an 11 goes over 21, they choose ACE 1, if not, ACE 11
				if ((cardNum < 22) || (handSize == 0)) {
					cardAssign = "ACE 11";
				}
				else if (cardNum > 22) {
					cardAssign = "ACE 1";
				}
				else {
					cardAssign = "ACE 1";
				}
			}
		}
		else if (card > 1 && card < 11) { // CARDS 2 TO 10
			cardAssign = to_string(card);
		}
		else if (card == 11) { // JACK
			cardAssign = "Jack";
		}
		else if (card == 12) { // QUEEN
			cardAssign = "Queen";
		}
		else if (card == 13) { // KING
			cardAssign = "King";
		}

		if (handSize == 2) {
			for (int i = 0; i < 2; i++) {
				if ((hand[0] == cardAssign) && (suit[0] == suit[1])) { // Makes sure card isn't played again    
					validCard = false;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < (handSize - 1); i++) {
				if ((hand[i] == cardAssign) && (suit[i] == suit[handSize - 1])) { // Makes sure card isn't played again       
					validCard = false;
					break;
				}
			}
		}
		if (validCard) {
			break;
		}

		recursionDepth++;
	}
	if (recursionDepth >= maxRecursionDepth) {
		return ""; 
	}
	/* 
	for (int i = 0; i < dealerSize; i++) {
		if (dealerHand[i] == cardAssign && dealerSuit[i] == suit[handSize]) { // Makes sure card isn't played again   
			randomCard(player, hand, handSize, suit);      
		}
	}

	for (int i = 0; i < secondSize; i++) {
		if (seconfHand[i] == cardAssign && secondSuit[i] == suit[handSize]) { // Makes sure card isn't played again
			randomCard(player, hand, handSize, suit);
		}
	}
	*/
	// Default return statement
	return cardAssign;
}

void playerMenu(string playerChoice, string* playerHand, string* playerSuit, int& handSize, bool& done, bool hasEqualCards, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int& betPlaced, int& secondSize, bool& doubledDown, bool& hasPassed) { 
	if (playerChoice == "H" || playerChoice == "h") {
		hitTurn(playerHand, handSize, playerSuit, true);
	} 
	if (playerChoice == "S" || playerChoice == "s") { 
		standTurn();
		done = true;
	}
	if (playerChoice == "SP" || playerChoice == "sp") {
		if (hasSplit == true) {
			cout << "-----------------------------------------------------------" << endl;
			cout << "You have already split your hand." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		else if (hasEqualCards == true) {
			hasSplit = true;
			splitTurn(hasEqualCards, playerHand, playerSuit, secondHand, secondSuit, hasSplit, totalBet, betPlaced, handSize); 
		}
		else {
			cout << "-----------------------------------------------------------" << endl;
			cout << "Split cannot be done. Your cards are not the same." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
	}
	if (playerChoice == "D" || playerChoice == "d") {
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
	if (playerChoice == "X" || playerChoice == "x") {
		passTurn(hasPassed);  
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

void winLoseConditions(string playerHand[], int handSize, string dealerHand[], int dealerSize, int& totalBet, int betPlaced, bool& gameRunning, bool& hasPassed) {  
	// WIN CONDITIONS: IF PLAYER HAS MORE CARD COUNT THAN DEALER BUT LESS THAN 22 AND IF DEALER HAS > 21 

	if (hasPassed) {
		cout << "Dealer takes half the bet!" << endl; 
		totalBet -= (betPlaced / 2); 
		cout << "\nBalance: " << totalBet << endl; 
	}

	else {
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
	
}

// Asking user to play again  
void playAgain(bool& gameRunning, int totalBet) {

	bool validEntry = false; 

	while (!validEntry) {
		if (totalBet > 0) {
			cout << "\nPlay again? Y/N: ";
			string choice;
			cin >> choice;

			if (choice == "Y" || choice == "y") {
				gameRunning = true;
				validEntry = true; 
			}
			else if (choice == "N" || choice == "n") {
				gameRunning = false;
				validEntry = true;  
			}
			else {
				cout << "\nEnter valid input." << endl; 
				validEntry = false;
			}
		} 
	}
	
}

//Print out the balance
void printBalance(int totalBet) {
	cout << "Balance is " << totalBet << endl;
}