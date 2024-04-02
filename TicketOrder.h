#ifndef TICKETORDER_H
#define TICKETORDER_H
#include "LinkticketQ.h"
#include "NodeQ.h"
using namespace std;

class TicketOrder
{
    private:
        string ticketID;
        int quantity;
        LinkticketQ *TicketOrdered;
    public:
        TicketOrder();
        void addTicket(NodeQ *, int);
        void removeTicket();
        double getTotalPrice();
        void print();
        void printSeller();
};

#endif