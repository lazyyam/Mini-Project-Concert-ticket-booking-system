#include "Ticket.h"
#include <iostream>

using namespace std;

Ticket::Ticket()
{
    ID="";
	price=0;
	position="";
	quantity=0;
	next=NULL; //IMPORTANT FOR (curr!=NULL) -> loop
}

void Ticket::setTicket(NodeQ* _ticket, int _quantity)
{
    ID = _ticket -> ticketid;
    position = _ticket -> position;
    price = _ticket ->price;
    quantity = _quantity;
}

double Ticket::getTotal() //
{
	return price*quantity;
}