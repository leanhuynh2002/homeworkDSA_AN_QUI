#pragma once
#ifndef TREEPRIORITY_H
#define TREEPRIORITY_H
#include <iostream>
using namespace std;

struct TreePrio
{
	string ID;
	unsigned int Order;
	unsigned int Priority;
	TreePrio* left = NULL;
	TreePrio* right = NULL;
	int length = 1;
};

//----------------------------------------------------
// swap

void swap(TreePrio*& p1, TreePrio*& p2);

//---------------------------------------------
// check the conditions

bool check(TreePrio*& node);

//-----------------------------------------------

// read a line in file txt
void getData(fstream& file, TreePrio*& root);

// load data
TreePrio* readFile(string nameFile);

//--------------------------------------------------
// sort data

void heapify(TreePrio*& node);

//--------------------------------------------------
// compare two different node
bool compare(TreePrio* p1, TreePrio* p2);

//-----------------------------------------------
// check the root is NULL

bool isEmpty(TreePrio*& root);

//------------------------------------------------
// insert a new node into mean-heap

void Insert(TreePrio*& root, TreePrio* node);

//----------------------------------------------------
// delete all anode
void deleteAllNode(TreePrio*& root);

//-----------------------------------------------------
// print one node

void printNode(TreePrio* node);

// print into console to check
void printConsole(TreePrio*& root);

//---------------------------------------------------------

// remove the node has add last into min-heap
TreePrio* removeTheLastNode(TreePrio* node, TreePrio* preNode = NULL);

// remove the node has largest priority
TreePrio* Extract(TreePrio*& root);

//-------------------------------------------------------------

// find the node has the given ID
TreePrio* findID(TreePrio* root, string ID);

// remove the node contains the give ID
void Remove(TreePrio* root, string ID);

//------------------------------------------------------------------

// change priority of the node contains the given ID and sort min-heap
void changePriority(TreePrio* root, string ID, unsigned int inputPriority);

#endif