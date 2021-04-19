// Participants: Thien Vu
// Date: 04-19-21
// Description: war game header
#pragma once
#include <deque>
#include <iostream>
#include <chrono> 
#include <algorithm>
#include <random>
using namespace std;

//Precondition: cardsPerSuite is less then 14 and greater than 0, argument for generalDeck is an int deque
//Postcondition: generates the number of cards in generalDeck based on cardsPerSuite; Ex:  cardsPerSuite = 5 -> 20 cards in generalDeck
void generateGeneralDeck(int cardsPerSuite, deque <int>& generalDeck);

//Precondition: argument for deck is an int deque
//Postcondition: displays all the numbers in deck
void displayDeck(deque <int> deck);

//Precondition: argument for deck is an int deque
//Postcondition: shuffles deck
void shuffleDeck(deque <int>& deck);

//Precondition: N/A
//Postcondition: gets input for cardsPerSuite
int getCardsPerSuite();

//Precondition: arguments for generalDeck, player1Deck, and player2Deck are int deques
//Postcondition: deals the cards in generalDeck evenly to player1Deck and player2Deck
void dealCards(deque <int>& generalDeck, deque <int>& player1Deck, deque <int>& player2Deck);

//Precondition: arguments for generalDeck, player1Deck, and player2Deck are int deques
//Postcondition: checks to see whether player 1 or player 2 wins the turn, or if there's a war going on, then who wins the war
void warGame(deque<int>& player1Deck, deque<int>& player2Deck, deque <int>& tempDeckForWar);

//Precondition: arguments for generalDeck, player1Deck, and player2Deck are int deques
//Postcondition: plays warGame and displays messages for the game
void playWarGame(deque<int>& player1Deck, deque<int>& player2Deck, deque <int>& tempDeckForWar);