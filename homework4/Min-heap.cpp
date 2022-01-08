#include "Min-heap.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

////----------------------------------------------------
//// swap
//
//void swap(TreePrio*& p1, TreePrio*& p2)
//{
//	swap(p1->ID, p2->ID);
//	swap(p1->Order, p2->Order);
//	swap(p1->Priority, p2->Priority);
//}
//
////---------------------------------------------
//// check the conditions
//
//bool check(TreePrio*& node)
//{
//	if (node->length == 1 || node->length == 0)
//		return false;
//	int ptemp = (int)log2(node->length + 1);
//	if ((int)pow(2, ptemp) == (node->length + 1)) {
//		return true;
//	}
//	return false;
//}
//
////-----------------------------------------------
//
//// read a line in file txt
//void getData(fstream& file, TreePrio*& root)
//{
//	string ID;
//	unsigned int Order, Priority;
//	TreePrio* node = NULL;
//
//	while (!file.eof()) {
//		file >> Order >> Priority;
//		getline(file, ID);
//		if (ID == "") {
//			return;
//		}
//		ID.erase(0, 1);
//		node = new TreePrio{ ID, Order, Priority};
//		Insert(root, node);
//		node = NULL;
//	}
//}
//
//// load data
//TreePrio* readFile(string nameFile)
//{
//	TreePrio* root = NULL;
//	fstream file(nameFile, ios::in);
//	if (file.fail()) {
//		throw "Can't open FILE !\n";
//	}
//	getData(file, root);
//	file.close();
//	return root;
//}
//
////--------------------------------------------------
//// sort data
//
//void heapify(TreePrio*& node)
//{
//	TreePrio* smallest = node;
//	TreePrio* l = node->left;
//	TreePrio* r = node->right; // right = 2*i + 2
//
//	// If left child is larger than root
//	if (l != NULL && compare(smallest, l))
//		smallest = l;
//
//	// If right child is larger than largest so far
//	if (r != NULL && compare(smallest, r))
//		smallest = r;
//
//	// If largest is not root
//	if (smallest != node) {
//		//printNode(smallest);
//		swap(smallest, node);
//
//		// Recursively heapify the affected sub-tree
//		heapify(smallest);
//	}
//}
//
////--------------------------------------------------
//// compare two different node
//bool compare(TreePrio* p1, TreePrio* p2)
//{
//	// compare the Priority
//	if (p1->Priority > p2->Priority)
//		return true;
//	else if (p1->Priority < p2->Priority)
//		return false;
//	// compare the Order
//	else {
//		if (p1->Order > p2->Order)
//			return true;
//		else if (p1->Order < p2->Order)
//			return false;
//	}
//
//	throw "Error from input data !\n";
//}
//
////-----------------------------------------------
//// check the root is NULL
//
//bool isEmpty(TreePrio*& root)
//{
//	if (root == NULL)
//		return true;
//	return false;
//}
//
////------------------------------------------------
//// insert a new node into mean-heap
//
//void Insert(TreePrio*& root, TreePrio* node)
//{
//	// the List is sorted before
//	// we just add 1 element
//	// add first left, right after	
//	// if the root is larger than the element need insert, swap them
//	if (isEmpty(root)) {
//		root = node;
//	}
//	else {
//		++root->length;
//		// compare the root
//		if (compare(root, node)) {
//			swap(root, node);
//			// root add one element in its tree
//		}
//
//		// check for children of root
//		if (isEmpty(root->left)) {
//			Insert(root->left, node);
//		}
//		else if (isEmpty(root->right)) {
//			Insert(root->right, node);
//		}
//		else {
//			// left are full
//			if (check(root->left)) {
//				if (check(root->right) && root->right->length == root->left->length) {
//					Insert(root->left, node);
//				}
//				// right not full, insert right
//				else {
//					Insert(root->right, node);
//				}
//			}
//			// left not full, insert left
//			else {
//				Insert(root->left, node);
//			}
//		}
//	}
//}
//
////----------------------------------------------------
//// delete all anode
//void deleteAllNode(TreePrio*& root)
//{
//	if (root != NULL) {
//		deleteAllNode(root->left);
//		deleteAllNode(root->right);
//		delete root;
//		root = NULL;
//	}
//}
//
////-----------------------------------------------------
//// print one node
//
//void printNode(TreePrio* node)
//{
//	if (node != NULL) {
//		cout << node->ID << " " << node->Order << " " << node->Priority << endl;
//	}
//}
//
//// print into console to check
//void printConsole(TreePrio*& root)
//{
//	if (root != NULL) {
//		printNode(root);
//		if (root->left != NULL) {
//			printConsole(root->left);
//		}
//		if (root->right != NULL) {
//			printConsole(root->right);
//		}
//	}	
//}
//
////---------------------------------------------------------
//
//// remove the node has add lastest into min-heap
//TreePrio* removeTheLastNode(TreePrio* node, TreePrio* preNode)
//{
//	if (node != NULL) {
//		// if left is full, check right
//		// if left and right are NULL, node is the last
//		// because node->length == 1 is not full, so it can happen
//		//           root
//		//         /      \
//		//        p1        p2
//		//---------------------------------------------------------------
//		if (check(node)) {
//			preNode = node;
//			--preNode->length;
//			return removeTheLastNode(node->right, preNode);
//		}
//		else if (node->left != NULL) {
//			if (check(node->left)) {
//				if (node->right != NULL) {
//					if (!check(node->right)) {
//						if (node->right->length > 1) {
//							preNode = node;
//							--preNode->length;
//							return removeTheLastNode(node->right, preNode);
//						}
//						else {
//							preNode = node;
//							--preNode->length;
//							return removeTheLastNode(node->left, preNode);
//						}
//					}
//					else {
//						preNode = node;
//						--preNode->length;
//						return removeTheLastNode(node->left, preNode);
//					}
//				}
//				else {
//					preNode = node;
//					--preNode->length;
//					return removeTheLastNode(node->left, preNode);
//				}
//			}
//			else {
//				preNode = node;
//				--preNode->length;
//				return removeTheLastNode(node->left, preNode);
//			}
//		}
//		else {
//			if (preNode != NULL) {
//				if (preNode->left == node) {
//					preNode->left = NULL;
//				}
//				else {
//					preNode->right = NULL;
//				}
//				return node;
//			}
//		}
//	}
//	else {
//		return NULL;
//	}
//}
//
//// remove the node has largest priority
//void Extract(TreePrio*& root)
//{
//	// find the latest node
//	TreePrio* lastNode = removeTheLastNode(root);
//	if (lastNode != NULL) {
//		// swap the data between root and lastest node
//		swap(root, lastNode);
//		// sorted the min-heap again
//		heapify(root);
//	}
//}
//
////-------------------------------------------------------------
//
//// find the node has the given ID
//TreePrio* findID(TreePrio* root, string ID)
//{
//	if (root != NULL) {
//		if (root->ID == ID) {
//			return root;
//		}
//		TreePrio* l = findID(root->left, ID);
//		TreePrio* r = findID(root->right, ID);
//		if (l != NULL) {
//			return l;
//		}
//		else if (r != NULL) {
//			return r;
//		}
//	}
//
//	return NULL;
//}
//
//// remove the node contains the give ID
//void Remove(TreePrio* root, string ID)
//{
//	// find the node has the ID
//	TreePrio* foundNode = findID(root, ID);
//	if (foundNode != NULL) {
//		// find the last node of min-heap
//		TreePrio* lastNode = removeTheLastNode(root);
//		// if the node need deleted is different from last node of min-heap
//		if (foundNode != lastNode) {
//			swap(foundNode, lastNode);
//			// sorted the min-heap again
//			heapify(foundNode);
//		}
//		// delete the node contains data of the node need delete
//		delete lastNode;
//	}
//}
//
////------------------------------------------------------------------
//
//// change priority of the node contains the given ID and sort min-heap
//void changePriority(TreePrio* root, string ID, unsigned int inputPriority)
//{
//	// find the node need change priority
//	TreePrio* foundNode = findID(root, ID);
//	if (foundNode != NULL) {
//		// make a new node from the current foundNode to insert again
//		foundNode = new TreePrio{ foundNode->ID, foundNode->Order, inputPriority };
//		// remove the old foundNode (it is in min-heap in the moment)
//		Remove(root, ID);
//		// add it again into min-heap
//		Insert(root, foundNode);
//	}
//}

//----------------------------------------------------------------
// sort up and down from a position

// get the data from file
void getData(fstream& file, min_heap& _p)
{
	string ID;
	unsigned int Priority;

	while (!file.eof()) {
		file >> Priority;
		getline(file, ID);
		if (ID == "") {
			return;
		}
		ID.erase(0, 1);
		Insert(_p, User(ID, Priority));
	}
}

// open file
void readFile(string nameFile, min_heap& _p)
{
	fstream file(nameFile, ios::in);
	if (file.fail()) {
		return;
	}
	getData(file, _p);
	file.close();
}

//----------------------------------------------------------------
// sort up to up
void heapifyUp(min_heap& _p, int index)
{
	int root;
	if (index % 2 == 0) {
		root = index / 2 - 1;
	}
	else {
		root = index / 2;
	}

	if (root < 0)
		return;

	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int largest = root;
	int size = _p._arr.size();

	// find the index smallest
	if (left < size && compare(_p._arr[left], _p._arr[largest]) == 1) {
		largest = left;
	}

	if (right < size && compare(_p._arr[right], _p._arr[largest]) == 1) {
		largest = right;
	}

	if (largest != root) {
		swap(_p._arr[largest], _p._arr[root]);
		heapifyUp(_p, root);
	}
}

// sort down to down
void heapifyDown(min_heap& _p, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	int size = _p._arr.size();

	// find the index smallest
	if (left < size && compare(_p._arr[left], _p._arr[largest]) == 1) {
		largest = left;
	}

	if (right < size && compare(_p._arr[right], _p._arr[largest]) == 1) {
		largest = right;
	}

	if (largest != index) {
		swap(_p._arr[largest], _p._arr[index]);
		heapifyDown(_p, largest);
	}
}

//----------------------------------------------------------------
// print all node into console
void printConsole(min_heap& root)
{
	for (auto u : root._arr) {
		cout << print(u) << endl;
	}
}

//----------------------------------------------------------------
// clear the vector
void deleteAllNode(min_heap& root)
{
	root._arr.clear();
}

//----------------------------------------------------------------
// check the vector has no member
bool isEmpty(const min_heap& _p)
{
	if (_p._arr.size() == 0) {
		return true;
	}
	return false;
}

// insert one user into vector
void Insert(min_heap& _p, User _input)
{
	// push it into tail of vector
	_p._arr.push_back(_input);
	// heapify up
	heapifyUp(_p, _p._arr.size() - 1);
}

// delete the highest in min-heap
void Extract(min_heap& _p)
{
	int size = _p._arr.size();
	if (size > 1) {
		// swap the lastest and head of min-heap, then delete the lastest of min-heap
		swap(_p._arr[0], _p._arr[size - 1]);
		_p._arr.pop_back();
		// heapify down
		heapifyDown(_p, 0);
	}
}

// remove the node with given ID
void Remove(min_heap& _p, string ID)
{
	// find the node contains the given ID
	int i = 0;
	for (; i < _p._arr.size(); i++) {
		if (_p._arr[i].ID == ID) {
			// swap it with the tail of min-heap
			swap(_p._arr[i], _p._arr[_p._arr.size() - 1]);
			// delete the tail
			_p._arr.pop_back();
			break;
		}
	}

	// heapify the min-heap
	heapifyDown(_p, i);
	heapifyUp(_p, i);
}

// change the priority of one node contains the given ID and sort min-heap
void changePriority(min_heap& _p, string ID, unsigned int _inputPriority)
{
	// find the node contains the given ID
	for (int i = 0; i < _p._arr.size(); i++) {
		if (_p._arr[i].ID == ID) {
			// if its has larger inprioriy -> heapifyup
			if (_p._arr[i].Priority > _inputPriority) {
				_p._arr[i].Priority = _inputPriority;
				heapifyUp(_p, i);
			}
			// heapify down
			else if (_p._arr[i].Priority < _inputPriority) {
				_p._arr[i].Priority = _inputPriority;
				heapifyDown(_p, i);
			}
			return;
		}
	}
}