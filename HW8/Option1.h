// Participants: Thien Vu
// Date: 04-15-21
// Description: 

#pragma once
#include <deque>
#include <iostream>
#include <chrono> 
#include <algorithm>
#include <random>
using namespace std;

void generateGeneralDeck(int cardsPerSuite, deque <int>& generalDeck)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= cardsPerSuite; j++)
		{
			generalDeck.push_front(j);
		}
	}
}

void displayDeck(deque <int> deck)
{
	int count = 0;
	deque <int>::iterator it;
	for (it = deck.begin(); it != deck.end(); ++it)
	{
		if (count == 10)
		{
			cout << "\n\t\t";
			count = 0;
		}
		cout << '\t' << *it;
		count++;
	}
	cout << '\n';
}

void shuffleDeck(deque <int>& deck)
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

int getCardsPerDeck()
{
	int cardsPerDeck;
	do
	{
		cout << "\n\tEnter a number of cards per suite: ";
		cin >> cardsPerDeck;
		if (cardsPerDeck > 13 || cardsPerDeck < 1)
		{
			cout << "\n\tError: Invalid Input\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else if (cin.fail())
		{
			cout << "\n\tError: Invalid input.\n";
			cin.clear();
			cin.ignore(999, '\n');
		}
		else
		{
			break;
		}
	} while (true);

	return cardsPerDeck;
}

void dealCards(deque <int> &generalDeck, deque <int>& player1Deck, deque <int>& player2Deck)
{
	while (!generalDeck.empty())
	{
		player1Deck.push_front(generalDeck.front());
		generalDeck.pop_front();

		player2Deck.push_front(generalDeck.front());
		generalDeck.pop_front();
	}
}

void warGame(deque<int>& player1Deck, deque<int>& player2Deck, deque <int>& tempDeckForWar)
{
	if (player1Deck.front() > player2Deck.front())
	{
		player1Deck.push_back(player1Deck.front());
		player1Deck.pop_front();

		player1Deck.push_back(player2Deck.front());
		player2Deck.pop_front();
	}
	else if (player1Deck.front() < player2Deck.front())
	{
		player2Deck.push_back(player1Deck.front());
		player1Deck.pop_front();

		player2Deck.push_back(player2Deck.front());
		player2Deck.pop_front();
	}
	else if (player1Deck.front() == player2Deck.front())
	{
		for (int i = 0; i < 4; i++)
		{
			if (player1Deck.empty() || player2Deck.empty())
				break;
			else
			{
				tempDeckForWar.push_front(player1Deck.front());
				player1Deck.pop_front();

				tempDeckForWar.push_front(player2Deck.front());
				player2Deck.pop_front();
			}
		}

		if (player1Deck.empty() && player2Deck.empty())
		{
			return;
		}
		else if (player1Deck.empty())
		{
			shuffleDeck(tempDeckForWar);

			while (!tempDeckForWar.empty())
			{
				player2Deck.push_back(tempDeckForWar.front());
				tempDeckForWar.pop_front();
			}
			return;
		}
		else if (player2Deck.empty())
		{
			shuffleDeck(tempDeckForWar);

			while (!tempDeckForWar.empty())
			{
				player1Deck.push_back(tempDeckForWar.front());
				tempDeckForWar.pop_front();
			}
			return;
		}
		else
		{
			deque <int> tempDeck(player1Deck);

			warGame(player1Deck, player2Deck, tempDeckForWar);

			while (!tempDeckForWar.empty() && !player1Deck.empty() && !player2Deck.empty())
			{
				if (tempDeck.size() > player1Deck.size())
				{
					for(int i = 0 ; i < 2; i++)
					{
						tempDeckForWar.push_front(player2Deck.back());
						player1Deck.push_front(player2Deck.back());
						player2Deck.pop_back();
					}
					shuffleDeck(tempDeckForWar);
					while (!tempDeckForWar.empty())
					{
						player2Deck.push_back(tempDeckForWar.front());
						tempDeckForWar.pop_front();
					}
				}
				else if (tempDeck.size() < player1Deck.size())
				{
					for (int i = 0; i < 2; i++)
					{
						tempDeckForWar.push_front(player1Deck.back());
						player2Deck.push_front(player1Deck.back());
						player1Deck.pop_back();
					}
					shuffleDeck(tempDeckForWar);
					while (!tempDeckForWar.empty())
					{
						player1Deck.push_back(tempDeckForWar.front());
						tempDeckForWar.pop_front();
					}
				}
			}
		}
	}
	
}

void playWarGame(deque<int>& player1Deck, deque<int>& player2Deck, deque <int>& tempDeckForWar)
{
	while (!player1Deck.empty() && !player2Deck.empty())
	{
		if (player1Deck.front() > player2Deck.front())
		{
			cout << "\n\tPlayer1: " << player1Deck.front();
			cout << "\t\tPlayer2: " << player2Deck.front();
			cout << "\t\t -> Player1 wins!\n";
			warGame(player1Deck, player2Deck, tempDeckForWar);

			cout << "\n\n\tPlayer 1: ";
			displayDeck(player1Deck);

			cout << "\n\tPlayer 2: ";
			displayDeck(player2Deck);
		}
		else if (player1Deck.front() < player2Deck.front())
		{
			cout << "\n\tPlayer1: " << player1Deck.front();
			cout << "\t\tPlayer2: " << player2Deck.front();
			cout << "\t\t -> Player2 wins!\n";
			warGame(player1Deck, player2Deck, tempDeckForWar);

			cout << "\n\n\tPlayer 1: ";
			displayDeck(player1Deck);

			cout << "\n\tPlayer 2: ";
			displayDeck(player2Deck);
		}
		else if (player1Deck.front() == player2Deck.front())
		{
			cout << "\n\tPlayer1: " << player1Deck.front();
			cout << "\t\tPlayer2: " << player2Deck.front();
			cout << "\t\t -> A war begins!\n";

			deque <int> tempDeck(player1Deck);

			warGame(player1Deck, player2Deck, tempDeckForWar);

			if (player1Deck.empty() && player2Deck.empty())
			{
				break;
			}
			else if (player1Deck.empty())
			{
				cout << "\n\tPlayer1 doesn't have enough cards for the war -> Player2 wins the war\n";
			}
			else if (player2Deck.empty())
			{
				cout << "\n\tPlayer2 doesn't have enough cards for the war -> Player1 wins the war\n";
			}
			else
			{
				if (tempDeck.size() < player1Deck.size())
				{
					cout << "\tPlayer1: " << player2Deck.front();
					player2Deck.pop_front();

					cout << "\t\tPlayer2: " << player2Deck.front();
					player2Deck.pop_front();

					cout << "\t\t -> Player1 wins the war!\n";
				}
				else
				{
					cout << "\tPlayer1: " << player1Deck.front();
					player1Deck.pop_front();

					cout << "\t\tPlayer2: " << player1Deck.front();
					player1Deck.pop_front();

					cout << "\t\t -> Player2 wins the war!\n";
				}

				cout << "\n\n\tPlayer 1: ";
				displayDeck(player1Deck);

				cout << "\n\tPlayer 2: ";
				displayDeck(player2Deck);
			}
		}
		system("pause");
		cout << "\n\t\t" << string(70, char(205));

	}

	if (player1Deck.empty() && player2Deck.empty())
	{
		cout << "\n\tBoth Player1 and Player2 don't have enough cards left for the war.";
		cout << "\n\t\t Therefore, it's a tie\n";
	}
	else if (player1Deck.empty())
	{
		cout << "\n\tPlayer1 has no more cards.";
		cout << "\n\t\t Therefore, Player2 wins the game with " << player2Deck.size() << " cards\n";
	}
	else if (player2Deck.empty())
	{
		cout << "\n\tPlayer2 has no more cards.";
		cout << "\n\t\t Therefore, Player1 wins the game with " << player1Deck.size() << " cards\n";
	}
}