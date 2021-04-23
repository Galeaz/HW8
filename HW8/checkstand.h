// Participants: Gabriela Lopez, Andrew Thompson
// Date: 04-15-21
// Description: checkstand header
#pragma once
using namespace std;
#include <iostream>
#include <queue>
#include <ctime>
class checkoutQueue
{
private:
	queue<int> customers;
	int size;
public:
	//Precondition: N/A
	//Postcondition: default constructor, set size = 0
	checkoutQueue();
	//Precondition: N/A
	//Postcondition: return if size == 0
	bool empty() const;
	//Precondition: N/A
	//Postcondition: adds a customer to the line
	void addCustomer();
	//Precondition: N/A
	//Postcondition: remove a cusomter from Queue
	void removeCustomer();
	//Precondition: a checkoutQueue
	//Postcondition: overload the operator < to use with checkoutQueue
	bool operator <(const checkoutQueue& RHS);
	//Precondition: a checkoutQueue, and output ostream
	//Postcondition: overload the operator << to output checkoutQueue
	friend ostream& operator <<(ostream& outs,const checkoutQueue& obj);
	//percondition: a checkoutQueue
	//postcondition: returns the size of the queue
	int getSize() const;

};