#include "RBTree.h"
#include <iostream>
using namespace std;


RBNode* nil;

int main() {	
	nil = new RBNode;
	nil->color = 0;
	nil->left = nil->right = nil->parent = nil;

	RBNode* root;
	int a[] = { 10,20,38,16,95,54,78,66,3,8,14,41,26,19,90,93,85,32,49,100 };
	root = createTree(a, 20);
	cout << "a[20] = { 10,20,38,16,95,54,78,66,3,8,14,41,26,19,90,93,85,32,49,100 }\n";
	cout << "Tao cay do-den tu mang a[20].\n";
	cout << "Chieu cao: " << Height(root) << " - Chieu cao den: " << BlackHeight(root) << endl;
	cout << "Tim 41 trong cay." << ((lookUp(root, 41) != nil) ? " - Da tim thay.\n" : " - Khong tim thay.\n");
	cout << "Tim 50 trong cay." << ((lookUp(root, 50) != nil) ? " - Da tim thay.\n\n" : " - Khong tim thay.\n\n");

	Insert(root, 50);
	Insert(root, 15);
	cout << "Chen 50 va 15 vao cay.\n";
	cout << "Tim 50 trong cay." << ((lookUp(root, 50) != nil) ? " - Da tim thay.\n" : " - Khong tim thay.\n");
	cout << "Tim 15 trong cay." << ((lookUp(root, 15) != nil) ? " - Da tim thay.\n\n" : " - Khong tim thay.\n\n");

	Remove(root, 50);
	Remove(root, 41);
	cout << "Xoa 50 va 41 khoi cay.\n";
	cout << "Tim 50 trong cay." << ((lookUp(root, 50) != nil) ? " - Da tim thay.\n" : " - Khong tim thay.\n");
	cout << "Tim 41 trong cay." << ((lookUp(root, 41) != nil) ? " - Da tim thay.\n" : " - Khong tim thay.\n");
	cout << "Tim 15 trong cay." << ((lookUp(root, 15) != nil) ? " - Da tim thay.\n" : " - Khong tim thay.\n");
	cout << "Chieu cao: " << Height(root) << " - Chieu cao den: " << BlackHeight(root) << endl;

	deleteTree(root);
	delete nil;
}