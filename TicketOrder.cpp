#include "TicketOrder.h"
#include "Ticket.h"
#include "LinkticketQ.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

TicketOrder::TicketOrder()
{
	ticketID="";
	quantity=0;
	TicketOrdered=NULL;
}

void TicketOrder::addTicket(NodeQ * _ticket, int _quantity)
{
    if (TicketOrdered==NULL)
	{
		TicketOrdered=new LinkticketQ;
		TicketOrdered -> enqueueTicket(_ticket, _quantity);
		quantity++;
	}
    else// Update the size of array TicketOrdered and add new ticket into it
    {
        TicketOrdered->enqueueTicket(_ticket,_quantity);
		quantity++;
    }
}
void TicketOrder::removeTicket()
{
    if (quantity==0)
	{
	    cout<<"Invalid action !!!"<<endl;
		cout<<"There is no ticket added."<<endl;
	}
	else 
	{
		TicketOrdered->dequeueTicket();		
	}

}

double TicketOrder::getTotalPrice()// Return total price of all items in the order
{
	return TicketOrdered->getTotalPrice();
}

void TicketOrder::print()//
{
	cout<<"Cart"<<endl;
	cout<<"----------"<<endl;
	cout<<left<<setw(10)<<"No"<<setw(20)<<"ID"<<setw(40)<<"Position"<<setw(20)<<"Unit Price/RM"<<setw(20)<<"Quantity"<<setw(20)<<"Total Price/RM"<<endl;
    TicketOrdered->listticket();
	cout<<endl<<"Total Payment: RM"<<fixed<<setprecision(2)<<TicketOrdered->getTotalPrice()<<endl<<endl;
}

void TicketOrder::printSeller()
{
	TicketOrdered->listticket();
}

