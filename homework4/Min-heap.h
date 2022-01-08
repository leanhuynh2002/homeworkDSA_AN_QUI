#pragma once
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

struct min_heap
{
	vector<User> _arr;
};

//---------------------------------------------------------------

void getData(fstream& file, min_heap& _p);

void readFile(string nameFile, min_heap& _p);

//----------------------------------------------------------------
// sort up and down from a position

void heapifyUp(min_heap& _p, int index);

void heapifyDown(min_heap& _p, int index);

//----------------------------------------------------------------

void printConsole(min_heap& root);

//----------------------------------------------------------------

void deleteAllNode(min_heap& root);

//----------------------------------------------------------------
// function 

bool isEmpty(const min_heap& _p);

void Insert(min_heap& _p, User _input);

void Extract(min_heap& _p);

void Remove(min_heap& _p, string ID);

void changePriority(min_heap& _p, string ID, unsigned int _inputPriority);