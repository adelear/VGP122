#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
#include "gameplay.h" 

using namespace std;

int main() {

	srand(time(nullptr)); // Making sure new random number is generated every time program runs

	int totalBet = 1000;
	bool gameRunning = true;
	string dealerHand[21] = { "" };
	string dealerSuit[21] = { "" };
	string playerHand[21] = { "" };
	string playerSuit[21] = { "" };
	//If Player Splits 
	string secondHand[21] = { "" };
	string secondSuit[21] = { "" };

	// Main Game loop
	while (gameRunning) {
		int betPlaced;
		string playerChoice;
		int cardNum = 0;
		int handSize = 2;
		int secondSize = 2;
		int dealerSize = 0;
		bool validBet = false;
		bool hasEqualCards = false;
		bool hasSplit = false;
		bool doubledDown = false;
		bool hasPassed = false;

		//Printing out Balance
		while (!validBet) {
			printBalance(totalBet);
			cout << "Place your bet: ";
			cin >> betPlaced;

			if (cin.fail() || betPlaced > totalBet || betPlaced < 1) {
				cout << "Invalid Bet." << endl;
				cin.clear(); // clearing input buffer 
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoring any remaining characters 
			}
			else {
				validBet = true;
			}
		}

		cout << "---------------------------------------------------------------" << endl;
		cout << "Dealing Cards" << endl;

		//PLAYER'S HAND
		cout << "----------------------------" << endl;
		cout << "YOUR HAND" << endl;
		playerSuit[0] = randomSuit(handSize, playerSuit, playerHand); 
		playerHand[0] = randomCard(true, playerHand, handSize, playerSuit); 
		cout << "\nFirst card: " << playerHand[0] << " " << playerSuit[0] << endl; 
		playerSuit[1] = randomSuit(handSize, playerSuit, playerHand);  
		playerHand[1] = randomCard(true, playerHand, handSize, playerSuit);  
		cout << "Second card: " << playerHand[1] << " " << playerSuit[1] << endl;
		cout << "Card Count: " << cardCount(playerHand, handSize) << endl;
		cout << "----------------------------" << endl;

		//DEALER'S HAND 
		cout << "DEALER'S HAND" << endl;
		dealerHand[0] = randomCard(false, dealerHand, dealerSize, dealerSuit);  
		dealerSuit[0] = randomSuit(dealerSize, dealerSuit, dealerHand); 
		cout << "\nFirst card: " << dealerHand[0] << " " << dealerSuit[0] << endl;  
		dealerSize = 2;  
		dealerHand[1] = randomCard(false, dealerHand, dealerSize,dealerSuit);   
		dealerSuit[1] = randomSuit(dealerSize, dealerSuit, dealerHand);    
		cout << "Second card: UNFLIPPED " << endl;
		cout << "----------------------------" << endl;

		//MENU FOR PLAYER OPTIONS
		bool playerDone = false;
		
		//If the player has split their hand, this will output to differentiate between the two hands
		if (hasSplit) {
			cout << "-----------------------------------------------------------" << endl;
			cout << "PLAYING FIRST HAND" << endl;
		}
		while (handSize < 22 && cardCount(playerHand, handSize) < 22 && !playerDone) {
			//Gives the option to split if and only if the first two cards are the same 
			if (handSize == 2 && playerHand[0] == playerHand[1]) {
				hasEqualCards = true;
				cout << "\nHit(H) | Stand(S) | Split(SP) | Double Down(D) |  Pass(X): ";
			}
			else {
				cout << "\nHit(H) | Stand(S) | Double Down(D) |  Pass(X): ";
			}
			cin >> (playerChoice);
			playerMenu(playerChoice, playerHand, playerSuit, handSize, playerDone, hasEqualCards, secondHand, secondSuit, hasSplit, totalBet, betPlaced, secondSize, doubledDown, hasPassed); 
			printBoard(playerHand, playerSuit, handSize);
		}

		//reveal dealear Cards 
		cout << "\nRevealing Dealer's Hand: " << dealerHand[0] << " " << dealerSuit[0] << "| " << dealerHand[1] << " " << dealerSuit[1] << endl;

		//Dealer hits until they have more than 21 or than player 
		//if player has more than 21, dealer doesn't hit
		//if player has the same count as the dealer
		while (cardCount(dealerHand, dealerSize) <= cardCount(playerHand, handSize) && (cardCount(dealerHand, dealerSize) < 18) && (cardCount(playerHand,handSize) < 22)) {      
			hitTurn(dealerHand, dealerSize, dealerSuit, false);   
		}

		//Win Lose Draw Conditions  
		winLoseConditions(playerHand, handSize, dealerHand, dealerSize, totalBet, betPlaced, gameRunning, hasPassed);  

		//Playing secondhand 
		if (hasSplit) { 
			if (doubledDown) { 
				betPlaced = betPlaced / 2;  //Resetting Bet if the player doubled down for their first hand  
			}
			cout << "----------------------------" << endl;
			cout << "PLAYING SECOND HAND" << endl;
			printBoard(secondHand, secondSuit, secondSize);

			bool playerDone2 = false;
			while (handSize < 22 && cardCount(secondHand, secondSize) < 22 && !playerDone2) {

				cout << "\nHit(H) | Stand(S) | Double Down(D) |  Pass(X): ";
				cin >> (playerChoice);

				playerMenu(playerChoice, secondHand, secondSuit, secondSize, playerDone2, hasEqualCards, secondHand, secondSuit, hasSplit, totalBet, betPlaced, secondSize, doubledDown, hasPassed); 
				printBoard(secondHand, secondSuit, secondSize);
			}
			winLoseConditions(secondHand, secondSize, dealerHand, dealerSize, totalBet, betPlaced, gameRunning, hasPassed); //Checks the win lose conditions  
		}

		//Playing again? 
		playAgain(gameRunning, totalBet);
	}
	return 0;
}

