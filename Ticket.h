#ifndef _TICKET_H_
#define _TICKET_H_
#include "NodeQ.h"
#include <string>

using namespace std;

class Ticket
{
    public:
        string ID;
        double price;
        string position;
        int quantity;
        Ticket *next;
        Ticket();
        void setTicket(NodeQ *, int);
        double getTotal();        
};

#endif