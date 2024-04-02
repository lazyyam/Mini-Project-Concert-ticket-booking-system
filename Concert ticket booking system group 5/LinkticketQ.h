#ifndef LINKTICKETQ_H
#define LINKTICKETQ_H
#include "Ticket.h"
#include "NodeQ.h"
using namespace std;

class LinkticketQ
{
    private:
		Ticket *front, *back, *curr;
	public:
		LinkticketQ();
		~LinkticketQ();
		bool isEmpty();
		void enqueueTicket(NodeQ *, int);
		void dequeueTicket();
		void listticket();
		double getTotalPrice();
};

#endif