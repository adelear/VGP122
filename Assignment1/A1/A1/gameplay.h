#pragma once
#ifndef GAMEPLAY_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define GAMEPLAY_H

#include <iostream>
#include <string>
#include <bitset>
#include <cstdlib>
using namespace std;

void hitTurn(string* playerHand, int& handSize, string* playerSuit, bool player);
void standTurn();
void splitTurn(bool equalCards, string* playerHand, string* playerSuit, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int betPlaced, int& handSize); 
void doubleDown(int& betPlaced, string* playerHand, string* playerSuit, int& handSize, bool& doubledDown); 
void passTurn(bool& hasPassed); 
int cardCount(string cardArray[], int arraySize);
string randomSuit(int& handSize, string* suit, string* card);  
int addCard(string* hand, string* suit, int& cardCount, string card, string cardSuit);
string randomCard(bool player, string* hand, int& handSize, string* playerSuit);    
void playerMenu(string playerChoice, string* playerHand, string* playerSuit, int& handSize, bool& done, bool hasEqualCards, string* secondHand, string* secondSuit, bool& hasSplit, int& totalBet, int& betPlaced, int& secondSize, bool& doubledDown, bool& hasPassed); 
void printBoard(string playerHand[], string playerSuit[], int handSize);
void winLoseConditions(string playerHand[], int handSize, string dealerHand[], int dealerSize, int& totalBet, int betPlaced, bool& gameRunning, bool& hasPassed); 
void playAgain(bool& gameRunning, int totalBet);
void printBalance(int totalBet);

#endif   