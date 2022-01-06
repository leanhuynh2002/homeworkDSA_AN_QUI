#include "Priority.h"
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

//----------------------------------------------------

// compare two node different
bool Condition(PrioQue* p1, PrioQue* p2)
{
	// compare the priority
	if (p1->Priority > p2->Priority)
		return true;
	else if (p1->Priority < p2->Priority)
		return false;
	// compare the Order
	else {
		if (p1->Order > p2->Order)
			return true;
		else if (p1->Order < p2->Order)
			return false;
	}

	throw "Error from input data !\n";
}

//-----------------------------------------------------

// check the list is empty
bool isEmpty(List& root)
{
	if (root.head == NULL)
		return true;
	return false;
}

//-----------------------------------------------------

// insert one node into list
void Insert(List& l, PrioQue* node)
{
	// insert for root
	if (isEmpty(l)) {
		l.head = node;
	}
	// the List is sorted before
	// we just add 1 element
	else {
		PrioQue* pre = NULL;
		PrioQue* pnext = l.head;

		for (; pnext != NULL; pnext = pnext->next) {
			// find the node lower than it
			if (!Condition(pnext, node)) {
				// insert for head
				if (pnext == l.head) {
					node->next = l.head;
					l.head = node;
					return;
				}
				// insert between head and tail
				else {
					pre->next = node;
					node->next = pnext;
					return;
				}
			}
			pre = pnext;
		}

		// add for tail
		if (pre == NULL) {
			throw "Error in Insert !\n";
		}
		else {
			pre->next = node;
		}
	}
}

//----------------------------------------------------------

// delete one node
void deleteNode(PrioQue* node)
{
	if (node != NULL) {
		node->next = NULL;
		delete node;
	}
}

// delete all node
void deleteAllNode(List& l)
{
	// contain the deleted node
	PrioQue* node;

	// delete iff l.head == NULL
	while (!isEmpty(l)) {
		node = l.head;
		l.head = l.head->next;
		deleteNode(node);
	}
}

//---------------------------------------------------------------

// read a line in file txt
void getData(fstream& file, List& l)
{
	unsigned int Order, Priority;
	string ID;
	PrioQue* node = NULL;

	while (!file.eof()) {
		file >> Order >> Priority;
		getline(file, ID);
		if (ID == "") {
			return;
		}
		ID.erase(0, 1);
		node = new PrioQue{ ID, Order, Priority };
		Insert(l, node);
		node = NULL;
	}
}

// load data
void readFile(string nameFile, List& l)
{
	fstream file(nameFile, ios::in);
	if (file.fail()) {
		throw "Can't open File !\n";
	}
	getData(file, l);
	file.close();
}

//----------------------------------------------------------------

// print a node
void printNode(PrioQue* node)
{
	if (node != NULL) {
		cout << node->ID << " " << node->Order << " " << node->Priority;
	}
}

// print all nodes
void printConsole(List& l)
{
	for (PrioQue* p = l.head; p != NULL; p = p->next) {
		printNode(p);
		cout << "\n";
	}
}

//-----------------------------------------------------

// find the node and remove it
PrioQue* findAndRemove(List& l, string ID)
{
	PrioQue* pre = NULL, * pnext = l.head;

	for (; pnext != NULL; pnext = pnext->next) {
		// if find the node that contains the given ID
		if (pnext->ID == ID) {
			// if it is head, change head node
			if (pnext == l.head) {
				l.head = l.head->next;
			}
			// change the preNode
			else {
				pre->next = pnext->next;
			}
			pnext->next = NULL;
			return pnext;
		}
		pre = pnext;
	}

	return NULL;
}

// change the priority of one node contains given priority
void changePriority(List& l, string ID, int inputPriority)
{
	// find the node contain the given ID
	PrioQue* foundNode = findAndRemove(l, ID);
	// chang its priority and insert it into the LinkedList
	if (foundNode != NULL) {
		foundNode->Priority = inputPriority;
		Insert(l, foundNode);
	}
}

//--------------------------------------------------------

// remove a node contains the given ID
void Remove(List& l, string ID)
{
	PrioQue* pre = NULL, * pnext = l.head;

	// pnext contain the needed node
	for (; pnext != NULL; pnext = pnext->next) {
		if (pnext->ID == ID) {
			if (pnext == l.head) {
				l.head = l.head->next;
			}
			else {
				pre->next = pnext->next;
			}
			// delete the node contain the given ID
			deleteNode(pnext);
			return;
		}
		pre = pnext;
	}
}

//---------------------------------------------------------

// remove the node has largest priority
void Extract(List& l)
{
	if (!isEmpty(l)) {
		PrioQue* p = l.head;
		l.head = l.head->next;
	}
}