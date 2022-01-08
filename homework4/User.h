#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct User
{
	static int InstanceCount;
	string ID;
	unsigned int Order;
	unsigned int Priority;

	User(string _ID, unsigned int _Priority)
	{
		ID = _ID;
		Order = InstanceCount++;
		Priority = _Priority;
	}
};

void swap(User& a, User& b);

int compare(const User& p1, const User& p2);

string print(const User& _p);