#include <iostream>
#include "Priority.h"
#include "TreePriority.h"
using namespace std;

int main()
{
	// load data
	List l;
	readFile("D:\\HW4-Priority.txt", l);

	// all works
	try {
		printPriority(l);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	// delete all memories
	deleteAllPiority(l);


	try {
		TreePrio* root = readFile("D:\\HW4-Priority.txt");
		cout << "\n---------------------------------------------------------\n";
		changePriority(root, "Thao", 5);
		printConsole(root);
		deleteAllNode(root);
	}
	catch (const char* str) {
		cout << str << endl;
	}

	return 1;
}