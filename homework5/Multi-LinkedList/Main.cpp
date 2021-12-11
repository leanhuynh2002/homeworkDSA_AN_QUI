#include "MultiLinkedList.h"
#include <iostream>
using namespace std;


int main() {
	FILE* fileIn = fopen("input.txt", "r");	

	Lref head, tail, p, q;
	Tref t;
	int x, y, z;
	head = new Leader;
	tail = head;
	z = 0;

	// Doc file input va tao list
	while (!feof(fileIn)) {
		fscanf(fileIn, "(%d,%d)", &x, &y);
		p = addList(head, tail, x, z);
		q = addList(head, tail, y, z);
		t = new Trailer;
		t->id = q;
		t->next = p->trail;
		p->trail = t;
		q->count++;
	}

	// Sap xep Topo va xuat ket qua
	// Tao danh sach cac node khong co node cha
	p = head;
	head = NULL;
	while (p != tail) {
		q = p;
		p = p->next;
		if (q->count == 0) {
			q->next = head;
			head = q;
		}
	}
	// Xuat ket qua va xoa node theo trinh tu
	q = head;
	while (q) {
		cout << q->key << " ";
		z--;
		t = q->trail;
		Lref del = q;
		q = q->next;
		delete del;
		while (t) {
			p = t->id;
			p->count--;
			if (p->count == 0) {
				p->next = q;
				q = p;
			}
			t = t->next;
		}
	}

	fclose(fileIn);
}