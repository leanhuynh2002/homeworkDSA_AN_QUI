#include <iostream>
#include "MultiLinkedList.h"
//#include <stdio.h>
using namespace std;




Lref addList(Lref& head, Lref& tail, int w, int& z) {
	Lref h = head;
	tail->key = w;
	while (h->key != w) {
		h = h->next;
	}
	if (h == tail) {
		tail = new Leader;
		z++;
		h->count = 0;
		h->trail = NULL;
		h->next = tail;
	}
	return h;
}

