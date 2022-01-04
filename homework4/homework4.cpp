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
		cout << "Kiem tra co rong hay khong: ";

		if (!isEmpty(l)) {
			cout << "Non empty !\n";
		}
		cout << "\n";

		cout << "Them vao: ID: Vo Thanh, order = 5, priority = 4 \n";
		PrioQue* node = new PrioQue{ "Vo Thanh", 5, 4 };
		Insert(l, node);
		cout << "Danh sach sau khi them \n";
		printConsole(l);
		cout << "\n";

		cout << "Lay phan tu xep cao nhat\n";
		Extract(l);
		cout << "Danh sach khi xoa\n";
		printConsole(l);
		cout << "\n";

		cout << "Xoa phan tu voi ID = An\n";
		Remove(l, "An");
		cout << "Danh sach khi xoa\n";
		printConsole(l);
		cout << "\n";

		cout << "Thay doi priority cua phan tu voi ID = Tu Van Qui, inputpriority = 7\n";
		changePriority(l, "Tu Van Qui", 7);
		cout << "Danh sach sau khi thay doi\n";
		printConsole(l);

		deleteAllNode(l);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	cout << "\n---------------------------------------------------------------------------------------\n";

	try {
		TreePrio* root = readFile("HW4-Priority.txt");

		cout << "Kiem tra co rong hay khong: ";
		if (!isEmpty(root)) {
			cout << "Non empty !\n";
		}
		cout << "\n";

		cout << "Them vao: ID: Vo Thanh, order = 5, priority = 4 \n";
		TreePrio* node = new TreePrio{ "Vo Thanh", 5, 4 };
		Insert(root, node);
		cout << "Danh sach sau khi them \n";
		printConsole(root);
		cout << "\n";

		cout << "Lay phan tu xep cao nhat\n";
		Extract(root);
		cout << "Danh sach khi xoa\n";
		printConsole(root);
		cout << "\n";

		cout << "Xoa phan tu voi ID = An\n";
		Remove(root, "An");
		cout << "Danh sach khi xoa\n";
		printConsole(root);
		cout << "\n";

		cout << "Thay doi priority cua phan tu voi ID = Tu Van Qui, inputpriority = 2\n";
		changePriority(root, "Tu Van Qui", 2);
		cout << "Danh sach sau khi thay doi\n";
		printConsole(root);

		deleteAllNode(root);

	}
	catch (const char* str) {
		cout << str << endl;
	}

	return 1;
}