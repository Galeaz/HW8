// Participants: Gabriela Lopez
// Date: 04-15-21
// Description: file containing Drivers for option3

#pragma once
#include <iostream>
using namespace std;

#include "input.h"

//Precondition: N/A
//Postcondition: contains driver for checkstands at CostCo
void option3()
{
	system("cls");
	cout << "\n\t3> Simulation of checkout lines at a CostCo warehouse store\n";
	int timeOperating = inputInteger("\n\tEnter the time (0..37800 in seconds) of the store will be operated: ", 0, 37800);
	int numberOfCheckstands = inputInteger("\n\tEnter the number of cash registers (1..10): ", 1, 10);
}