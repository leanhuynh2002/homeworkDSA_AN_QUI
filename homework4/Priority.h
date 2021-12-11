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


void swap(PrioQue* p1, PrioQue* p2);

bool Condition(PrioQue* p1, PrioQue* p2);

void Sort(List& l, PrioQue* node);

bool isEmpty(List& root);

void Insert(List& l, PrioQue* node);

void deleteNode(PrioQue* node);

void deleteAllPiority(List& l);

//------------------------------------------------------------

void getData(fstream& file, List& l);

void readFile(string nameFile, List& l);

void printNode(PrioQue* node);

void printPriority(List& l);

//------------------------------------------------

void Remove(List& l, string ID);

#endif