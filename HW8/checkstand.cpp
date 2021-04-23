// Participants: Gabriela Lopez, Andrew Thompson 
// Date: 04-15-21
// Description: checkstand implementation
#include "checkstand.h"
#include <random>
#include <Windows.h>
checkoutQueue::checkoutQueue() : size(0) {} 
bool checkoutQueue::empty() const
{
	return (size == 0);
}

void checkoutQueue::addCustomer()
{
	int customer = rand() % 100 + 1;
	customers.push(customer);
	size++;
}

void checkoutQueue::removeCustomer()
{
	
	customers.pop();
	size--;
}

bool checkoutQueue::operator <(const checkoutQueue& RHS)
{
	return(this->size < RHS.size);
}

ostream& operator <<(ostream& outs, const checkoutQueue& obj)
{
	if (obj.empty())
	{
		outs << " " << '\n';
		return outs;
	}
	else if(obj.size==1)
	{
		outs << "|/" << obj.customers.front() << "/|\n";
		return outs;
	}
	else
	{
		outs << "|/" << obj.customers.front() << "/|\t\t";
		for (int i = 1; i < obj.size; i++)
		{
			outs << string(3,254) << "\t"; //|///|
		}
		outs << '\n';
		return outs;
	}
}