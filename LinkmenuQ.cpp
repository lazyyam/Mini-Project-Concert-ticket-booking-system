#include "NodeQ.h"
#include "LinkmenuQ.h"
#include <iostream>
#include <iomanip>

using namespace std;


LinkmenuQ::LinkmenuQ() //constructor
{ 
	front = NULL;
    back = NULL;
}

LinkmenuQ::LinkmenuQ(NodeQ* n)
{
	front = n;
}

NodeQ* LinkmenuQ::nodeExists(string ticket){
	NodeQ * temp = NULL;
	NodeQ * ptr = new NodeQ;
	ptr = front;
	while (ptr != NULL){
		if (ptr->ticketid == ticket){
			temp = ptr;
		}
		ptr = ptr->next;	
	}
	return temp;
}

bool LinkmenuQ::isEmpty()
{
	return (front == NULL && back == NULL);
}

void LinkmenuQ::enQueue(NodeQ *n)
{
	NodeQ *newNode = new NodeQ;
    newNode = n;

    if(isEmpty()){
        front = newNode;
    }
    else 
        back->next = newNode;
            
    back = newNode;
}

void LinkmenuQ::DisplayList()
{
    NodeQ *tmp = front;
	cout << left << setw(15) << "Ticket ID" << setw(15) << "Position" << setw(15) << "Price(RM)" << endl;
	while(tmp != NULL)
	{
		cout<<left<<setw(15)<<tmp->ticketid<<setw(15)<<tmp->position<<setw(15)<<fixed<<setprecision(2)<<tmp->price<<endl;
		tmp = tmp->next;
    }
}

void LinkmenuQ::FindNodeDisplay(string x)
{
	NodeQ* currNode = front;
	int currIndex = 1;
	while (currNode && currNode->ticketid != x) 
	{
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode)
	{
		cout << "TicketID  :" << currNode->ticketid << endl;
		cout << "Position  :" << currNode->position << endl;
		cout << "Price(RM) :" << currNode->price << endl;
	}
	else
		cout << "Invalid input" << endl;
}
