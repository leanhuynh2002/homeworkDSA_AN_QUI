#pragma once
#ifndef PRIORITY_H
#define PRIORITY_H
#include <iostream>
using namespace std;

struct PrioQue 
{
	string ID;
	unsigned int Order;
	unsigned int Priority;
	PrioQue* next = NULL;
};

struct List
{
	PrioQue* head = NULL;
};

//----------------------------------------------------

// compare two node different
bool Condition(PrioQue* p1, PrioQue* p2);

//-----------------------------------------------------

// check the list is empty
bool isEmpty(List& root);

//-----------------------------------------------------

// insert one node into list
void Insert(List& l, PrioQue* node);

//----------------------------------------------------------

// delete one node
void deleteNode(PrioQue* node);

// delete all node
void deleteAllNode(List& l);

//---------------------------------------------------------------

// read a line in file txt
void getData(fstream& file, List& l);

// load data
void readFile(string nameFile, List& l);

//----------------------------------------------------------------

// print a node
void printNode(PrioQue* node);

// print all nodes
void printConsole(List& l);

//-----------------------------------------------------

// find the node and remove it
PrioQue* findAndRemove(List& l, string ID);

// change the priority of one node contains given priority
void changePriority(List& l, string ID, int inputPriority);

//--------------------------------------------------------

// remove a node contains the given ID
void Remove(List& l, string ID);

//---------------------------------------------------------

// remove the node has largest priority
void Extract(List& l);

#endif