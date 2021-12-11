#include "RadixSort.h"
#include <iostream>
using namespace std;

static int times;

int getDigits(Nref a, int k, int r) {
	return (a->key % (int)pow(10, k * r)) / pow(10, k * (r - 1));
}

void readInput(FILE* fileIn, int& k, int& n, Nref &head, Nref &tail) {
	fscanf(fileIn, "%d %d\n", &k, &n);
	head = new Node;
	fscanf(fileIn, "%d ", &(head->key));
	head->next = NULL;
	tail = head;
	while (!feof(fileIn)) {
		Nref node = new Node;
		fscanf(fileIn, "%d ", &(node->key));
		tail->next = node;
		node->next = NULL;
		tail = node;
		while (node->key / (int)pow(10, k * times) > 0)
			times++;
	}
}

void radixSort(int k, Nref &head, Nref &tail, Bref &buckDump)
{
	for (int cnt = 1; cnt <= times; cnt++) {
		buckDump = new Bucket;
		buckDump->head = buckDump->tail = NULL;
		buckDump->id = 0;
		buckDump->next = new Bucket;
		buckDump->next->head = buckDump->next->tail = head;
		buckDump->next->id = getDigits(head, k, cnt);
		buckDump->next->next = NULL;

		Nref h = head->next;
		while (h) {
			int h_id = getDigits(h, k, cnt);
			Bref p1 = buckDump;
			Bref p2 = buckDump->next;
			while (p2 && p2->id < h_id) {
				p1 = p1->next;
				p2 = p2->next;
			}
			if (!p2) {
				Bref newB = new Bucket;
				newB->id = h_id;
				newB->head = newB->tail = h;
				newB->next = NULL;
				p1->next = newB;

			}
			else if (p2->id == h_id) {
				p2->tail->next = h;
				p2->tail = h;
			}
			else {
				Bref newB = new Bucket;
				newB->id = h_id;
				newB->head = newB->tail = h;
				p1->next = newB;
				newB->next = p2;
			}
			h = h->next;
		}

		head = buckDump->next->head;
		tail = buckDump->next->tail;
		Bref b = buckDump->next->next;
		delete buckDump->next;
		delete buckDump;
		while (b) {
			tail->next = b->head;
			tail = b->tail;
			Bref temp = b;
			b = b->next;
			delete temp;
		}
		tail->next = NULL;
	}
}

void printOutput(int n, Nref &head) {
	Nref p = head;
	for (int i = 0; i < n; i++) {
		cout << p->key << " ";
		Nref temp = p;
		p = p->next;
		delete temp;
	}
}