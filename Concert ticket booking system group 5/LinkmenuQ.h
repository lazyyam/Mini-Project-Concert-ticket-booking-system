#ifndef LINKMENUQ_H
#define LINKMENUQ_H
#include "NodeQ.h"
#include <iostream>
#include <iomanip>
using namespace std;

class LinkmenuQ
{
    private:
        NodeQ *front, *back;

    public:
        LinkmenuQ();
        LinkmenuQ(NodeQ *);
        NodeQ* nodeExists(string);
        bool isEmpty();
        void enQueue(NodeQ *);
        void DisplayList();
        void FindNodeDisplay(string x);
};

#endif