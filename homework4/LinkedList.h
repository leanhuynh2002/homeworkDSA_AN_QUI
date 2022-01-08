#pragma once
#include "User.h"
#include <iostream>
using namespace std;

struct Node
{
	User _user;
	Node* next = NULL;
};

struct List
{
	Node* head = NULL;
};

//-----------------------------------------------------

// check the list is empty
bool isEmpty(List& root);

//-----------------------------------------------------

// insert one node into list
void Insert(List& l, Node* node);

//----------------------------------------------------------

// delete one node
void deleteNode(Node* node);

// delete all node
void deleteAllNode(List& l);

//---------------------------------------------------------------

// read a line in file txt
void getData(fstream& file, List& l);

// load data
void readFile(string nameFile, List& l);

//----------------------------------------------------------------

// print all nodes
void printConsole(List& l);

//-----------------------------------------------------

// find the node and remove it
Node* findAndRemove(List& l, string ID);

// change the priority of one node contains given priority
void changePriority(List& l, string ID, int inputPriority);

//--------------------------------------------------------

// remove a node contains the given ID
void Remove(List& l, string ID);

//---------------------------------------------------------

// remove the node has largest priority
void Extract(List& l);