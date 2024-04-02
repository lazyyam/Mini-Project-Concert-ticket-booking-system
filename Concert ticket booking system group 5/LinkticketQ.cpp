#include "Ticket.h"
#include "LinkticketQ.h"
#include "NodeQ.h"
#include <iostream>
#include <iomanip>
using namespace std;

LinkticketQ::LinkticketQ()
{
	front = NULL;
	back = NULL;
	curr = NULL;
}
LinkticketQ::~LinkticketQ()
{
		while(front!=NULL){
				curr=front;
				front=front->next;
				delete front;
			}
}

bool LinkticketQ::isEmpty()
{
	return (front == NULL && back == NULL);
}

void LinkticketQ::enqueueTicket(NodeQ *_ticket, int _quantity)
{
    Ticket *newticket = new Ticket;     
	newticket->setTicket(_ticket, _quantity);
    if(isEmpty())
    {
        front = newticket;
		back = newticket;
    }
    else
    {
        back->next = newticket;
		back = newticket;
    }
    
}
void LinkticketQ::dequeueTicket()
{
    Ticket *tmp = front;
	if (!isEmpty())
	{
		front = front->next;
		tmp->next = NULL;
		delete tmp;
	}
}

void LinkticketQ::listticket()
{
	int j=0;
	curr=front;
	while(curr!=NULL)
    {
	    cout<<left<<setw(10)<<j+1<<setw(20)<<curr->ID<<setw(40)<<curr->position;
	    cout<<left<<setw(20)<<fixed<<setprecision(2)<<curr->price<<setw(20)<<curr->quantity;
	    cout<<left<<setw(20)<<fixed<<setprecision(2)<<curr->getTotal()<<endl;
	    curr=curr->next;
		
	    j++;
    }
}

double LinkticketQ::getTotalPrice()// Return total price of all items in the order
{
	double totalPrice=0;
	curr=front;
	while(curr!=NULL)
    {
        totalPrice = totalPrice+curr->getTotal();
        curr=curr->next;
	}
	return totalPrice;
}