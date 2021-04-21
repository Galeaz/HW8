// Participants: Gabriela Lopez
// Date: 04-15-21
// Description: file containing Drivers for option3

#pragma once
#include <iostream>
using namespace std;

#include "input.h"
#include "checkstand.h"
#include <random>
#include <ctime>
//Precondition: N/A
//Postcondition: contains driver for checkstands at CostCo
bool timer(int timeOperating);
int generateCustomers();
void displayLine(vector<checkoutQueue>& vec);
void option3()
{
	vector<checkoutQueue> cq;
	int helped = 0;
	
	system("cls");
	cout << "\n\t3> Simulation of checkout lines at a CostCo warehouse store\n";
	int timeOperating = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int numberOfCheckstands = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);
	for (int i = 1; i <= numberOfCheckstands; i++)
	{
		checkoutQueue queue;
		cq.push_back(queue);
	}
	do
	{
		int customersPerLoop = generateCustomers();
		int counter = customersPerLoop;
		for (int i = 1;  i<customersPerLoop; i++)
		{
			if (numberOfCheckstands > 1)
			{
				if (i == cq.size()-1)
				{
					cq[i].addCustomer();
					counter--;
				}
				if (i >= cq.size())
					i = 1;
				if (counter == 0)
					break;
				if (cq[i] < cq[i - 1])
				{
					cq[i].addCustomer();
					counter--;
				}
				else 
				{
					cq[i - 1].addCustomer();
					counter--;
				}
				system("cls");
				displayLine(cq);
			}
			else 
			{
				cq[0].addCustomer();
				system("cls");
				displayLine(cq);
				counter--;
			}
		}
		for (int i = 0; i < cq.size(); i++)
			if (!cq[i].empty())
			{
				cq[i].removeCustomer();
				helped++;
			}
		system("cls");
		displayLine(cq);


	} while (timer(timeOperating));


}

void displayLine(vector<checkoutQueue> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\n'<<"Register " << i + 1 << '\n';
		cout << vec[i] << '\n';
	}

}
int generateCustomers()
{
	int amountOfCustomers = 6;
	int percentChance = 50; 
	int random = 0;
	for (int i = 0; i < 10; i++);
	{
		random = rand() % 100 + 1;
		if (random < 50)
			amountOfCustomers++;
	}
	return amountOfCustomers;
}
bool timer(int timeOperating)
{
	int stopTime = time(0) +timeOperating;
	return(time(0) < stopTime);
	
}