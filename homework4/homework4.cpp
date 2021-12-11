#include <iostream>
#include "Priority.h"
using namespace std;

int main()
{
	// load data
	List l;
	readFile("D:\\HW4-Priority.txt", l);

	// all works
	try {
		printPriority(l);

		Remove(l, "Le An");

		printPriority(l);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	// delete all memories
	deleteAllPiority(l);
	return 1;
}
