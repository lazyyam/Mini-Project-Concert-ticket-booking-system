#include <iostream>
#include "NodeQ.h"

using namespace std;


NodeQ::NodeQ(){
	ticketid = "";
	position = "";
	price = 0.0;
	next = NULL;
}

NodeQ::NodeQ(string t, string po, double pr){
	ticketid = t;
	position = po;
	price = pr;
};
