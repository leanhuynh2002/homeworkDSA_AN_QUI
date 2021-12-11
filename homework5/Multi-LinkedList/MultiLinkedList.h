#pragma once
#include <iostream>


typedef struct Leader* Lref;
typedef struct Trailer* Tref;
struct Leader {
	int key;
	int count;
	Lref next;
	Tref trail;
};
struct Trailer {
	Lref id;
	Tref next;
};

Lref addList(Lref& head, Lref& tail, int w, int& z);
