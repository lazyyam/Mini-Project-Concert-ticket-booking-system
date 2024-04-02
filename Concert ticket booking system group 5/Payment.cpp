#include "Payment.h"
#include <iostream>
#include <iomanip>
using namespace std;

Payment::Payment()
{
	status=false;
}

bool Payment::getStatus ()
{
	return status;
}