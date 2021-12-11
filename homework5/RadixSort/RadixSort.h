#pragma once
#include <iostream>
using namespace std;

typedef struct Bucket* Bref;
typedef struct Node* Nref;

struct Bucket {
	int id; 
	Nref head, tail;
	Bref next;
};
struct Node {
	int key;
	Nref next;
};

int getDigits(Nref a, int k, int r);
void readInput(FILE* fileIn, int& k, int& n, Nref &head, Nref &tail);
void radixSort(int k, Nref &head, Nref &tail, Bref &buckDump);
void printOutput(int n, Nref &head);
