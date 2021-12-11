#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "Lib.h"
using namespace std;

//---------------------------------------------------------

// make a new node
Node* createNode(char* name, char* type, vector<vector<int>> data)
{
	// Init a new node
	Node* ptemp = new Node();
	
	// add memory for name
	ptemp->name = new char[20];
	strcpy(ptemp->name, name);

	// add memory for type
	ptemp->type = new char[20];
	strcpy(ptemp->type, type);

	// copy data
	ptemp->data = data;

	return ptemp;
}

// delete completely a node
void deleteNode(Node* p)
{
	if (p != NULL) {
		// delete name va type
		delete p->name;
		delete p->type;

		// delete the pointer
		delete p;
	}
}

// add node to List from tail
Node* addTail(List& l, Node* Ptemp)
{
	// List is NULL,
	// add node for head
	if (l.head == NULL) {
		l.head = Ptemp;
	}
	else {
		// go to the tail of List
		Node* nex = l.head;
		while (nex->next != NULL) {
			nex = nex->next;
		}
		// add new node for tail
		nex->next = Ptemp;
	}

	return Ptemp;
}

//---------------------------------------------------------------

// find a node for a given name
Node* findNode(List& l, char* name)
{
	// check for the List
	for (Node* p = l.head; p != NULL; p = p->next) {
		// get a node with the same name
		if (strcmp(p->name, name) == 0) {
			return p;
		}
	}
	
	throw "Can't find NAME !\n";
}

// delete a node contail the same input Name
void deleteSimilarNode(List& l, const char* name)
{
	Node* pre = NULL;

	// check for all the nodes
	// get a node contains the name
	// delete it

	// check the head of List
	if (strcmp(l.head->name, name) == 0) {
		pre = l.head;
		l.head = l.head->next;
		deleteNode(pre);
		return;
	}

	// pre contail the node before p
	pre = l.head;

	// check nodes
	for (Node* p = l.head->next; p != NULL; p = p->next) {

		// get a node,
		// delete it
		if (strcmp(p->name, name) == 0) {
			pre->next = p->next;
			deleteNode(p);
			break;
		}

		pre = p;
	}
}

// delete the List
void deleteLinkedList(List& l)
{
	// ptemp contain the current head node of the List,
	// after delete List 's head node
	Node* ptemp = NULL;

	while (l.head != NULL) {
		ptemp = l.head;
		l.head = l.head->next;
		deleteNode(ptemp);
	}
}

//-----------------------------------------------------------------

// convert the data form terminal to vector
vector<int> ConvertFile(int argc, char** argv)
{
	vector<int> arr;

	for (int i = 4; i < argc; i++) {
		arr.push_back(atoi(argv[i]));
	}

	return arr;
}

// read the data of table we had worked
void readFile(List& l)
{
	// open the file save data
	fstream file;
	file.open("data.txt", ios_base::in);

	if (file.fail()) {
		throw "Can't open file !\n";
	}

	int size, n;
	vector<vector<int>> data;
	char* name = new char[20];
	char* type = new char[20];
	Node* p = NULL;

	// if we have a new name -> continue to read file

	// get the first name
	file.getline(name, 20);
	while (strcmp(name, "") == 0 && !file.eof()) {
		file.getline(name, 20);
	}

	while (strcmp(name, "") != 0 && !file.eof()) {

		// read type
		file.getline(type, 20);
		while (!file.eof() && strcmp(type, "") == 0) {
			file.getline(type, 20);
		}

		// read the size
		file >> size;
		data.resize(size);

		for (int i = 0; i < data.size(); i++) {
			file >> size;
			data[i].resize(size);
			for (int j = 0; j < data[i].size(); j++) {
				file >> n;
				data[i][j] = n;
			}
		}

		// create a node and add to the List
		p = createNode(name, type, data);
		addTail(l, p);

		data.clear();
		p = NULL;

		// get a new name again
		file.getline(name, 20);
		while (!file.eof() && strcmp(name, "") == 0) {
			file.getline(name, 20);
		}
	}

	delete[] name;
	delete[] type;

	file.close();
}

// write the List to the file
void writeFile(List& l)
{
	// open file
	fstream file;
	file.open("data.txt", ios_base::out);

	Node* p = l.head;

	// read all nodes of List
	while (p != NULL) {
		// write name and type
		file << p->name << endl;
		file << p->type << endl;

		// write the size
		file << p->data.size() << endl;

		for (int i = 0; i < p->data.size(); i++) {
			file << p->data[i].size() << endl;

			for (int j = 0; j < p->data[i].size(); j++) {

				// write the data
				file << " " << p->data[i][j];
			}
			file << endl;
		}
		file << endl;

		// go to the next node
		p = p->next;
	}

	file.close();
}

//------------------------------------------------------------------

// print table
void printTable(Node* p)
{
	// print name and type
	puts(p->name);
	puts(p->type);

	// print data
	for (auto u : p->data) {
		for (auto m : u) {
			cout << m << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// check the conditions to query data
void checkException(int L, int R, const vector<vector<int>>& table)
{
	if (L < 0 || L >= table.size() || L > R) {
		throw "Out of range !\n";
	}

	if (R < 0 || R >= table.size()) {
		throw "Out of range !\n";
	}
}

// find the GCD of int a, int b
int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else {
		while (a != b) {
			if (a > b)
				a -= b;
			else
				b -= a;
		}
	}

	return a;
}