#include "LinkedList.h"
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// check the list is empty
bool isEmpty(List& root)
{
	if (root.head == NULL)
		return true;
	return false;
}

//-----------------------------------------------------

// insert one node into list
void Insert(List& l, Node* node)
{
	// insert for root
	if (isEmpty(l)) {
		l.head = node;
	}
	// the List is sorted before
	// we just add 1 element
	else {
		Node* pre = NULL;
		Node* pnext = l.head;

		for (; pnext != NULL; pnext = pnext->next) {
			// find the node lower than it
			if (compare(pnext->_user, node->_user) == -1) {
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
void deleteNode(Node* node)
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
	Node* node;

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
	User ptemp;
	string ID;
	Node* node = NULL;

	while (!file.eof()) {
		file >> ptemp.Order >> ptemp.Priority;
		getline(file, ID);
		if (ID == "") {
			return;
		}
		ID.erase(0, 1);
		ptemp.ID = ID;
		node = new Node{ ptemp };
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

// print all nodes
void printConsole(List& l)
{
	for (Node* p = l.head; p != NULL; p = p->next) {
		cout << print(p->_user) << endl;
	}
}

//-----------------------------------------------------

// find the node and remove it
Node* findAndRemove(List& l, string ID)
{
	Node* pre = NULL, * pnext = l.head;

	for (; pnext != NULL; pnext = pnext->next) {
		if (pnext->_user.ID == ID) {
			if (pnext == l.head) {
				l.head = l.head->next;
			}
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
	Node* foundNode = findAndRemove(l, ID);
	// chang its priority and insert it into the LinkedList
	if (foundNode != NULL) {
		foundNode->_user.Priority = inputPriority;
		Insert(l, foundNode);
	}
}

//--------------------------------------------------------

// remove a node contains the given ID
void Remove(List& l, string ID)
{
	Node* pre = NULL, * pnext = l.head;

	// pnext contain the needed node
	for (; pnext != NULL; pnext = pnext->next) {
		if (pnext->_user.ID == ID) {
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
		Node* p = l.head;
		l.head = l.head->next;
		delete p;
	}
}