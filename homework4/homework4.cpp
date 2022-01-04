#include <iostream>
#include <string>
#include "Priority.h"
#include "TreePriority.h"
using namespace std;

int main()
{
	try {
		// load data
		List l;
		readFile("HW4-Priority.txt", l);

		if (!isEmpty(l)) {
			cout << "Non empty !\n";
		}
		PrioQue* node = new PrioQue{ "dsf", 5, 9};
		Insert(l, node);
		printConsole(l);
		cout << "\n";
		Extract(l);
		printConsole(l);
		cout << "\n";
		if (node != NULL) {
			delete node;
		}
		Remove(l, "An");
		printConsole(l);
		changePriority(l, "Qui", 7);
		deleteAllNode(l);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	cout << "\n---------------------------------------------------------------------------------------\n";

	try {
		TreePrio* root = readFile("HW4-Priority.txt");

		if (!isEmpty(root)) {
			cout << "Non empty !\n";
		}
		TreePrio* node = new TreePrio{ "dsf", 5, 9 };
		Insert(root, node);
		printConsole(root);
		cout << "\n";
		Extract(root);
		printConsole(root);
		cout << "\n";
		if (node != NULL) {
			delete node;
		}
		Remove(root, "An");
		printConsole(root);
		changePriority(root, "Qui", 7);
		deleteAllNode(root);
		
	}
	catch (const char* str) {
		cout << str << endl;
	}

	return 1;
}