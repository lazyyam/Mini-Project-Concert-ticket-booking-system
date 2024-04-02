#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "LinkmenuQ.h"
#include "Payment.h"
#include "TicketOrder.h"
#include "Ticket.h"
#include <iostream>

using namespace std;

class Customer
{
    private:
        TicketOrder ticketorder;
        Payment payment;
    public:
        string name;
        Customer *newcustomer;  
        Customer *next;
        Customer();
        void setName(string);
        string getName();
        void printPaymentDetails();
        void addBooking(LinkmenuQ *);
        void makePayment();
};

#endif