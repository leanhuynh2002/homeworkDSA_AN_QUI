#pragma once
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct User
{
	string ID;
	unsigned int Order;
	unsigned int Priority;
};

void swap(User& a, User& b);

int compare(const User& p1, const User& p2);

string print(const User& _p);