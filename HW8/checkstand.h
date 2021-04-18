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
	checkoutQueue();
	bool empty() const;
	void addCustomer();
	void removeCustomer();
	bool operator <(const checkoutQueue& RHS);
	friend ostream& operator <<(ostream& outs,const checkoutQueue& obj);
};