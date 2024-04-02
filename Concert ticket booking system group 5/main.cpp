#include <iostream>
#include <cstdio>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "NodeQ.h"
#include "Customer.h"
#include "LinkmenuQ.h"
#include "LinkcustomerQ.h"

using namespace std;


int main()
{
    LinkmenuQ *concertlist = new LinkmenuQ;
    LinkcustomerQ *custlist=new LinkcustomerQ;

    int userType;  //Customer or seller
    fstream infile;
    int lineCount = 0;  //number of line in the txt file
    string line;

    //count size of the file
    infile.open("menu.txt", ios::in); 
    if(!infile)
        cout << "Error: Cannot Open File." << endl;
    else
    {
        while(getline(infile, line)) 
            lineCount++;
        infile.close();

        string ticketid;
        string position;
        double price;

        //input menu to array
        infile.open("menu.txt", ios::in);
        for(int i=0; i<lineCount; i++)
        {
            NodeQ *add = new NodeQ;
            infile >> ticketid >> position >> price;
            add -> ticketid = ticketid;
	        add -> position = position;
	        add -> price = price;
            concertlist -> enQueue(add);

        }
        infile.close();

	}
    while(userType != 9)
    {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    cout << "Welcome to ABD Concert Ticket Booking System" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl<< endl;
    cout << "Please choose a user.\n1. Customer\n2. Seller\n\n9. Exit the program\n" << endl;
    cout << "Choose: ";
    cin >> userType;
    system("CLS");

    if (userType == 1) //Customer
            {
                int customerChoice = 0;
                while(customerChoice != 9)
                {
                    cout << "1. View ticket menu\n2. Add ticket booking\n3. Search ticket\n\n9. Back\n" << endl;
                    cout << "Enter your choice: ";
                    cin >> customerChoice;
                    system("CLS");
                    
                    int ccchoice =0;
                    if (customerChoice == 1)
                    {
                        while(ccchoice != 9)
                        {
                            cout<<"Ticket Menu"<<endl;
                            concertlist -> DisplayList();

                            cout << "Press 9 to go back: ";
                            cin >> ccchoice;
                            system ("CLS");
                        }
                    }
                    else if (customerChoice == 2)
                    {
                        custlist -> addCustomer(concertlist);
                    }
                    else if (customerChoice == 3)
                    {
                        string _ticketID;
                        cout << "Please enter the ticket ID from A to N" << endl;
                        cout << "Enter the ticket ID: ";
                        cin >> _ticketID;
                        cout << endl;
                        concertlist->FindNodeDisplay(_ticketID);
                        system("pause");
                        system("CLS");
                    }
                    else if(customerChoice == 9)
                    {

                    }
                }

            }
            else if (userType == 2) //Seller
            {
                int sellerChoice = 0;
                while(sellerChoice != 9)
                {
                    cout << "1. View ticket booking list\n\n9. Back\n" << endl;
                    cout << "Enter your choice: ";
                    cin >> sellerChoice;
                    system("CLS");
                    if (sellerChoice == 1)
                    {
                        custlist->listoutCustomer();
                    }
                    else
                    {
                        sellerChoice = 9;
                    }
                }
            }
            else if (userType == 9) //Exit
            {
                userType = 9;
                cout << "Thanks for using this program!" << endl;
                system("pause");
            }
            else
            {
                cout << "Input invalid, please enter 1, 2, or 9" << endl;
                system("pause");
                system("CLS");
            }
        
        
    }
    return 0;
}