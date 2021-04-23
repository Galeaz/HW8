// Participants: Long Duong, Christopher Gomez, Thien Vu
// Date: 04-15-21
// Description: file containing Drivers for option1

#pragma once
#include <iostream>
#include "wargame.h"
#include <time.h>
#include <vector>
#include <queue>
using namespace std;

//Precondition: N/A
//Postcondition: contains driver for war game
void option1()
{
	deque <int> generalDeck;
	deque <int> tempDeckForWar;
	deque <int> player1Deck;
	deque <int> player2Deck;

	cout << "\n\t1> Simulation of War (card game) using deque STL";
	cout << "\n\t" << string(100, char(205));

	generateGeneralDeck(getCardsPerSuite(), generalDeck);
	shuffleDeck(generalDeck);

	cout << "\n\tDeck of General Cards: ";
	displayDeck(generalDeck);

	dealCards(generalDeck, player1Deck, player2Deck);
	cout << "\n\n\tPlayer 1: ";
	displayDeck(player1Deck);
	cout << "\n\tPlayer 2: ";
	displayDeck(player2Deck);

	cout << "\n\tGame Starts:";
	cout << "\n\t\t" << string(70, char(205));

	playWarGame(player1Deck, player2Deck, tempDeckForWar);
}