#include "Customer.h"
#include "LinkmenuQ.h"
#include "LinkcustomerQ.h"
#include <iostream>
#include <iomanip>

using namespace std;

LinkcustomerQ::LinkcustomerQ()
{
	front = NULL;
	back = NULL;
	curr = NULL;
}

bool LinkcustomerQ::isEmpty()
{
	return (front == NULL && back == NULL);
}

void LinkcustomerQ::addCustomer(LinkmenuQ *concertlist)
{
	   	Customer *newcustomer = new Customer;     
		newcustomer->addBooking(concertlist);// invoke operations of adding and removing items from customer's order 
		if (isEmpty())// checking whether customer is the first to be added
		{
		    front = newcustomer;
			back = newcustomer;
		}
		else 
		{
			back->next = newcustomer;
		}
}

void LinkcustomerQ::listoutCustomer()
{
    curr=front;
	if (curr==NULL)
	{
			cout << "No Customer..." << endl;
            system("PAUSE");
            system("CLS");
	}
	else
	{
		while(curr!=NULL)
        {
			curr->printPaymentDetails();
			curr=curr->next;
		}
	}
}
