#include "User.h"
using namespace std;

void swap(User& a, User& b)
{
	swap(a.ID, b.ID);
	swap(a.Order, b.Order);
	swap(a.Priority, b.Priority);
}

int compare(const User& p1, const User& p2)
{
	// compare the priority
	if (p1.Priority < p2.Priority)
		return 1;
	else if (p1.Priority > p2.Priority)
		return -1;
	// compare the Order
	else {
		if (p1.Order < p2.Order)
			return 1;
		else if (p1.Order > p2.Order)
			return -1;
	}
	// same value
	return 0;
}

string print(const User& _p)
{
	stringstream writer;
	writer << "ID: " << _p.ID << "          Priority: " << _p.Priority << "         Order: " << _p.Order;
	return writer.str();
}