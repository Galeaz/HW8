// Participants: Gabriela Lopez, Andrew Thompson, Duyen Tran,
// Date: 04-15-21
// Description: file containing Drivers for option3. 

#pragma once
#include <iostream>
using namespace std;

#include "input.h"
#include "checkstand.h"
#include <random>
#include <ctime>
#include <Windows.h>

//Precondition: N/A
//Postcondition: contains driver for checkstands at CostCo
bool timer(int endTime);
int generateCustomers();

void displayLine(vector<checkoutQueue>& vec,int helped,int endTime);
int returnShortest(vector<checkoutQueue>& vec);
//Precondition: N/A
//Postcondition: Simulation of checkout lines at a Costco rather busy costco
void option3()
{
	vector<checkoutQueue> cq;
	int helped = 0;
	
	system("cls");
	cout << "\n\t3> Simulation of checkout lines at a CostCo warehouse store\n";
	int timeOperating = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int curtime = time(0);
	int endTime = curtime + timeOperating;
	int numberOfCheckstands = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);
	for (int i = 1; i <= numberOfCheckstands; i++)
	{
		checkoutQueue queue;
		cq.push_back(queue);
	}
	do
	{
		Sleep(100);
		int customersPerLoop = generateCustomers();
		for (int i = 1;  i<customersPerLoop; i++)
		{
			if (numberOfCheckstands > 1)
			{
				cq[returnShortest(cq)].addCustomer();
				system("cls");
				displayLine(cq, helped, endTime);
				if (!timer(endTime))
					break;
		
			}
			else 
			{
				cq[0].addCustomer();
				system("cls");
				displayLine(cq,helped,endTime);
			}
			
		}
		for (int i = 0; i < cq.size(); i++)
			if (!cq[i].empty() && (timer(endTime)))
			{
				cq[i].removeCustomer();
				helped++;
				system("cls");
				displayLine(cq, helped,endTime);
			}
	} while (timer(endTime)); 
}

//Precondition: a CheckoutQueue
//Postcondition: Create a number of checkout stands based on the user input
void displayLine(vector<checkoutQueue> &vec, int helped, int endTime)
{
	int currentTime = endTime - time(0);
	if (currentTime < 0)
		currentTime = 0;
	cout <<"Costco Warehouse store open for "<< currentTime << " \tNumber of customers served: " << helped<<'\n';
	for (int i = 0; i < vec.size(); i++)
	{
		cout << '\n'<<"Register " << i + 1 << '\n';
		cout << vec[i] << '\n';
	}
}
//Precondition: N/A
//Postcondition: returns a number between 6 and 7 for amount of customers per loop. must be a busy costco
int generateCustomers()
{
	int amountOfCustomers = 5;
	int percentChance = 50; 
	int random = 0;

	amountOfCustomers+= (rand()%2+1);
	return amountOfCustomers;
}
//Precondition: 2 integer
//Postcondition: Assign an operating time for the Checkstand in Costco
bool timer(int endTime)
{
	int holder;
	holder = time(0);
	return(holder < endTime);
}
//precondition: a vector of checkoutQueues
//postcondition: returns the shortest line
int returnShortest(vector<checkoutQueue>& vec)
{
	int shortest = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < vec[shortest])
			shortest = i;
	}
	return shortest;
}