// Participants: Long Duong, Christopher Gomez
// Date: 04-15-21
// Description: file containing Drivers for option1

#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <queue>
using namespace std;

//Precondition: N/A
//Postcondition: Prints menu and returns user int option selected
int menu1()
{
	cout << "\n\t1> Simulation of War (card game) using deque STL";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> ";
	cout << "\n\t\t2> ";
	cout << "\n\t\t3> ";
	cout << "\n\t\t0> return";
	cout << "\n\t" << string(100, char(205)) << '\n';
	int option = inputInteger("\n\tOption: ", 0, 3);
	return option;
}

//Precondition: N/A
//Postcondition: contains driver for 
void option1()
{
	system("cls");
	do
	{
		switch (menu1())
		{
		case 1:
		{

		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		}
	} while (true);
}