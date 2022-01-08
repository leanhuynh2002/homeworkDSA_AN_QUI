#include "Min-heap.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// get the data from file
void getData(fstream& file, min_heap& _p)
{
	User ptemp;
	while (!file.eof()) {
		file >> ptemp.Order >> ptemp.Priority;
		getline(file, ptemp.ID);
		if (ptemp.ID == "") {
			return;
		}
		ptemp.ID.erase(0, 1);
		Insert(_p, ptemp);
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
		largest = 2 * index + 1;
	}

	if (right < size && compare(_p._arr[right], _p._arr[largest]) == 1) {
		largest = 2 * index + 2;
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
	// delete the head of min-heap
	_p._arr.erase(_p._arr.begin(), _p._arr.begin() + 1);
	// heapify down
	heapifyDown(_p, 0);
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