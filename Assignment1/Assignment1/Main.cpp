/*

1. The player will begin the game with 1000 credits. They can use the credits to place bets
during each round of Blackjack played.

2. Once the player bets, a text-driven menu will provide options based on the hand dealt.
The menu should include the options: Hit(H), Stand(S), Split(P), Double Down (D), Pass
(X).

3. To calculate the card count, set all face cards to be worth 10 points (J, Q, K). Other
cards are worth the number value on the card (2, 3, 4,5 , 6, 7, 8, 9,1 0). 

Depending on the hand total, the ace is worth either 1 or 11

The game must include the following Blackjack rules:


1. The objective of the game is to beat the dealer by getting a total card count close to
or equal to 21 points, without going over 21


2. If the game is tied, the bet is returned to the player


3. The game begins by prompting the player to place a bet using the available credits


4. Cards will be dealt after the player places their bet, in alternating fashion, with two
cards dealt to the player face up, and two cards dealt to the dealer, one card face
up, and one face down


5. The player can request to hit, and will receive another card face up. The player can
hit until they reach a card count greater than 21
• The player can request to stand and the hand will be passed to the dealer
• If a pair of cards is dealt on initial deal, it can be split into two hands and another
card is dealt for each hand (implement only one split for this version)
*/
\


//WIN conditions: get closer to 21 than teh dealer withou tgoing over 21

//LOSE conditions: 
// 1: if the dealer gets closer to 21 than you
//2. if you go over 21

// POINTS
// 
// Cards 2-10 = Face Value
// Jack, Queen, King = 10
// Ace is 1 or 11 (Player gets to choose, whichever one is better for the hand

// HOW GAME IS DEALT

//Both player and the dealer get 2 cards
// Dealer only shows one card, the other card is facing down
// Player always goes first: 1) Hit(H) Stand(S) Split(S) Double Down(D) or Pass (X)


#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>

using namespace std;

void hitTurn(string playerHand[], int& handSize);
void standTurn();
void splitTurn();
void doubleDown();
void passTurn();
int cardCount(string cardArray[], int arraySize);
int addCard(string hand[], int& cardCount, string card);
string randomCard();
void playerMenu(string playerChoice, string playerHand[], int& handSize); 


void hitTurn(string playerHand[], int& handSize) {
	string newCard = randomCard();
	cout << "\nHit! New card: " << newCard << endl; 
	addCard(playerHand, handSize, newCard); 
	cout << "Card Count: " << cardCount(playerHand, handSize) << endl; 
}

void standTurn() { // Hold your total and end your turn 
	cout << "\nStand" << endl;
}

void splitTurn() {
	cout << "\nSplit" << endl;
}

void doubleDown() {
	cout << "\nDouble Down" << endl;
}

void passTurn() {
	cout << "\nPassed Turn!" << endl;
}

int cardCount(string cardArray[],int arraySize) {
	int count = 0;
	for (int i = 0; i < arraySize; i++) {

		//CONVERT IF STATEMENTS TO SWITCH OR MAP FOR LESS LINES (TODO)
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

int addCard(string hand[], int& cardCount, string card) { 
	hand[cardCount] = card;
	cardCount++;
	return cardCount;
}

// 
string randomCard() {
	int card = rand() % 13 + 1;

	if (card == 1) {
		bool validInput = false;
		cout << "\nCard: Ace 1 OR 11: " << endl;

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

void playerMenu(string playerChoice, string playerHand[], int& handSize) {
	if (playerChoice == "H") {
		hitTurn(playerHand, handSize); 
	}

	if (playerChoice == "S") {
		standTurn();
	}

	if (playerChoice == "SP") {
		splitTurn();
	}
	if (playerChoice == "D") {
		doubleDown();
	}
	if (playerChoice == "X") {
		passTurn();
	}
}

int main() {
	srand(time(nullptr)); // Making sure new random number is generated every time program runs

	int totalBet = 1000;
	bool gameRunning = true; 
	int cardNum = 0; 
	int handSize = 2;
	string dealerHand[10] = { "" };
	string playerHand[10] = { ""};

	while (gameRunning) {
		int bet;
		string playerChoice;

		cout << "---------------------------------------------------------------" << endl;
		cout << "Dealing Cards" << endl;
		//PLAYER'S HAND
		
		
		cout << "----------------------------" << endl;
		cout << "YOUR HAND" << endl;
		playerHand[0] = randomCard();
		cout << "\nFirst card: " << playerHand[0] << endl;
		playerHand[1] = randomCard();
		cout << "Second card: " << playerHand[1] << endl;
		cout << "\nCard Count: " << cardCount(playerHand, handSize) << endl;
		cout << "----------------------------" << endl;
	
		//DEALER'S HAND 
		cout << "DEALER'S HAND" << endl;
		
		dealerHand[0] = randomCard();  
		cout << "\nFirst card: " << dealerHand[0] << endl;  
		dealerHand[1] = randomCard();
		cout << "Second card: UNFLIPPED " << endl;
		cout << "----------------------------" << endl;


		

		//MAKE IF STATEMENT THAT CHECKS WHAT VALUE CARD IS SO THAT IT OUTPUTS KING, QUEEN, JACK, ACE, ETC


		cout << "Balance is " << totalBet << ". Place your bet : ";
		cin >> bet;
		totalBet = totalBet - bet;
		cout << "New Balance: " << totalBet << endl;


		//MENU FOR PLAYER OPTIONS

		while (handSize<22 && cardCount(playerHand, handSize)<22){
			cout << "\nHit(H) | Stand(S) | Split(SP) | Double Down(D) |  Pass(X) " << endl;
			cin >> (playerChoice);
			playerMenu(playerChoice, playerHand, handSize); 
		}
		
	}

		
	if (totalBet == 0) {
		cout << "You lost all your money!" << endl;

	}


	return 0;

}