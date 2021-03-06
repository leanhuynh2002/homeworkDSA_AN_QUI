#include <iostream>
#include <string>
#include "User.h"
#include "LinkedList.h"
#include "Min-heap.h"
using namespace std;

int User::InstanceCount = 0;

int main()
{
	try {
		cout << "+++++++++++++++++++++++++       LINKEDLIST           ++++++++++++++++++++++++++\n\n";
		// load data
		List l;
		readFile("HW4-Priority.txt", l);
		cout << "Kiem tra co rong hay khong: ";

		// demo function isEmpty
		if (!isEmpty(l)) {
			cout << "Non empty !\n";
		}
		cout << "\n";

		// demo function Insert
		cout << "Them vao: ID: Vo Thanh, priority = 4 \n";
		Node* node = new Node{ User("Vo Thanh", 4) };
		Insert(l, node);
		cout << "Danh sach sau khi them \n";
		printConsole(l);
		cout << "\n";

		// demo function Extract
		cout << "Lay phan tu xep cao nhat\n";
		Extract(l);
		cout << "Danh sach khi xoa\n";
		printConsole(l);
		cout << "\n";

		// demo function Remove
		cout << "Xoa phan tu voi ID = Bui Huy Thong\n";
		Remove(l, "Bui Huy Thong");
		cout << "Danh sach khi xoa\n";
		printConsole(l);
		cout << "\n";

		// demo function changePrioriy
		cout << "Thay doi priority cua phan tu voi ID = Tu Van Qui, inputpriority = 4\n";
		changePriority(l, "Tu Van Qui", 4);
		cout << "Danh sach sau khi thay doi\n";
		printConsole(l);

		// delete all node
		deleteAllNode(l);
	}
	catch (const char* message) {
		cout << message << endl;
	}

	cout << "\n++++++++++++++++++++++++++++           MIN-HEAP         +++++++++++++++++++++++++++++++++\n\n";

	try {
		cout << "*Print saved data from MIN-HEAP to Array, not sort Array*\n";
		User::InstanceCount = 0;
		// load data
		min_heap root;
		readFile("HW4-Priority.txt", root);

		// demo function isEmpty
		cout << "Kiem tra co rong hay khong: ";
		if (!isEmpty(root)) {
			cout << "Non empty !\n";
		}
		cout << "\n";

		// demo function Insert
		cout << "Them vao: ID: Vo Thanh, priority = 4\n";
		User ptemp("Vo Thanh", 4);
		Insert(root, ptemp);
		cout << "Danh sach sau khi them \n";
		printConsole(root);
		cout << "\n";

		// demo function Extract
		cout << "Lay phan tu xep cao nhat\n";
		Extract(root);
		cout << "Danh sach khi xoa\n";
		printConsole(root);
		cout << "\n";

		// demo function Remove
		cout << "Xoa phan tu voi ID = Bui Huy Thong\n";
		Remove(root, "Bui Huy Thong");
		cout << "Danh sach khi xoa\n";
		printConsole(root);
		cout << "\n";

		// demo function changePriority
		cout << "Thay doi priority cua phan tu voi ID = Tu Van Qui, inputpriority = 4\n";
		changePriority(root, "Tu Van Qui", 4);
		cout << "Danh sach sau khi thay doi\n";
		printConsole(root);

		// delete the min-heap
		deleteAllNode(root);

	}
	catch (const char* str) {
		cout << str << endl;
	}

	return 1;
}