#pragma once
//------------------------------------------

#include <vector>
using namespace std;

struct Node
{
   char* name = NULL;
   char* type = NULL;
   vector<vector<int>> data;
   Node* next = NULL;
};

struct List
{
   Node* head = NULL;
};

//---------------------------------------------

Node* createNode(char* name, char* type, vector<vector<int>> data);

Node* addTail(List& l, Node* ptemp);

void deleteNode(Node* p);

//------------------------------------------------

Node* findNode(List& l, char* name);

void deleteSimilarNode(List& l, const char* name);

void deleteLinkedList(List& l);

//-----------------------------------------------

vector<int> ConvertFile(int argc, char** argv);

void readFile(List& l);

void writeFile(List& l);

//------------------------------------------------

void printTable(Node* p);

void checkException(int L, int R, const vector<vector<int>>& table);

int gcd(int a, int b);