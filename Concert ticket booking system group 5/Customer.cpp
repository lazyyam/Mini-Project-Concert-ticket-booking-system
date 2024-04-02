#include "Customer.h"
#include "LinkmenuQ.h"
#include "Payment.h"
#include "TicketOrder.h"
#include "Ticket.h"
#include <iostream>
#include <iomanip>

using namespace std;

Customer::Customer()
{
	name="";
    next=NULL;
}

void Customer::setName(string n)
{
	name=n;
}
string Customer::getName()
{
    return name;
}
void Customer::printPaymentDetails() 
{
   int sortChoice = 0;

    while(sortChoice != 9)
    { 
    cout << "Customer's name: " << newcustomer->getName() << endl<< endl;
    cout<<left<<setw(20)<<"Ticket ID"<<setw(40)<<"Position"<<setw(20)<<"Unit Price/RM"<<setw(20)<<"Quantity"<<setw(20)<<"Total Price/RM"<<endl;
    ticketorder.printSeller();

    cout << "Next... Enter 9" << endl;
    cout << "Enter your choice: ";
    cin >> sortChoice;
    system("CLS");
    }

}
void Customer::addBooking(LinkmenuQ *concertlist)
{
    	int ticketquantity;
		string ticketid,position;
		double ticketprice;
		string tempid;
		int choice;
		cin.ignore();

        string name;
        cout<<"Please enter your name"<<endl;
        cout<<"Name: ";
        getline(cin,name);
		system("CLS");

        newcustomer = new Customer;     
		newcustomer->setName(name);// set customer's table number and name

        do
		{
			cout<<"Choose the below operations"<<endl;
			cout<<"1. Add ticket into your cart \n2. Remove ticket from your cart \n3. Make payment"<<endl;
			cout<<"Choice: ";
			cin>>choice;
			system("CLS");
			if (choice==1)
			{
                cout<<"Please add your ticket based on the menu"<<endl;
			    concertlist -> DisplayList();
                bool loop=true;
			    int index=-1;
				
                do
                {
                
                    int choice2;
                    cin.ignore();
                Q:
                    cout<<"Ticket ID: ";
                    getline (cin,ticketid);
                    cout<<"Quantity: ";
                    cin>>ticketquantity;
                    cin.ignore();	
                    NodeQ *tempnode;
				    tempnode=concertlist->nodeExists(ticketid);
				
				    if (tempnode==NULL)
				    {
                        cout<<"Invalid ticket id"<<endl;
                        goto Q;
				    }
				
	
				    ticketorder.addTicket(tempnode,ticketquantity);
                    
                E:
                    cout<<"Do you wish to add another ticket into your cart? \n 1. Yes \n 2. No"<<endl;
                    cout<<"Choice: ";
                    cin>>choice2;
                    if (choice2==1)
                    {
                        loop=true;
                        
                    }
                    else if (choice2==2)
                    {
                        loop=false;
                    }
                    else
                    {
                        cout<<"Invalid choice...Please try again"<<endl;
                        goto E;
                    }
                }
                while (loop);
                system("CLS");
                ticketorder.print();     
                  
            }
            else if(choice==2)
            {
                cout<<"The first ticket will be removed from your cart"<<endl;
                ticketorder.print();
                bool loop2=true;
                int index2;
                int choice2;

                do
                {
                    cin.ignore();
                    cout<<"The first ticket has been removed." << endl << endl;

                    ticketorder.removeTicket();

                H:
                    cout<<"Do you wish to remove another ticket into your cart? \n 1. Yes \n 2. No"<<endl;
                    cout<<"Choice: ";
                    cin>>choice2;
                    if (choice2==1)
                    {
                        loop2=true;
                        
                    }
                    else if (choice2==2)
                    {
                        loop2=false;
                    }
                    else
                    {
                        cout<<"Invalid choice...Please try again"<<endl;
                        goto H;
                    }
        
			    }
                while (loop2);
                system("CLS");
                ticketorder.print();
            }
            else if(choice==3) 
            {
                makePayment();
                system("pause");
                system("CLS");
            }
        }
		while (choice==1||choice==2);
}

void Customer::makePayment()
{
    if (!payment.getStatus()==false)// Checking whether the order has been made payment or not
	{
		cout<<"You haven't add any ticket in your cart."<<endl;
	}
    else
    {
        int choose;
        ticketorder.print();
        cout<<"======================================================"<<endl<<endl;
        cout<<"The total amount that you need to pay is RM "<<ticketorder.getTotalPrice()<<endl<<endl;
        cout<<">>Press 1 to confirm payment<<"<<endl;
        cin>>choose;
        system("CLS");
        do
        {
            cout<<"Payment completed."<<endl;
            
        }
        while(choose!=1);
    }
}


