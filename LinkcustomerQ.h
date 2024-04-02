#ifndef LINKCUSTOMERQ_H
#define LINKCUSTOMERQ_H
#include <iostream>
#include "Customer.h"
#include "LinkmenuQ.h"

using namespace std;

class LinkcustomerQ
{
	private:
		Customer *front, *back, *curr;
		
	public:
		LinkcustomerQ();
		bool isEmpty();
		void addCustomer(LinkmenuQ *);
		void listoutCustomer();

};

#endif