#ifndef NODEQ_H
#define NODEQ_H
#include <iostream>
using namespace std;

class NodeQ{
    public:
        string ticketid;
		string position;
		double price;

        NodeQ *next;

        NodeQ();
		NodeQ(string, string, double);
};

#endif
