#include "RBTree.h"
#include <iostream>
using namespace std;

// Nguon: Bai giang thay Phuong va https://freetuts.net/them-node-moi-vao-cay-do-den-3139.html

RBNode* createNode(int key, int color, RBNode* nil) {
	RBNode* p = new RBNode;
	p->key = key;
	p->color = color;
	p->left = p->right = p->parent = nil;
	return p;
}

void Insert(RBNode*& root, int key) {
	RBNode* x = createNode(key, 1, nil);
	RBNode* y = nil;
	RBNode* z = root;
	while (z != nil) {
		y = z;
		if (x->key < z->key)
			z = z->left;
		else if (x->key > z->key)
			z = z->right;
		else
			return;
	}
	x->parent = y;
	if (y == nil) root = x;
	else {
		if (x->key < y->key)
			y->left = x;
		else
			y->right = x;
	}
	Insertion_FixUp(root, x);
}

void rotateLeft(RBNode*& root, RBNode* pt)	// Xoay trai
{
	RBNode* pt_right = pt->right;
	pt->right = pt_right->left;
	if (pt->right != nil)
		pt->right->parent = pt;
	pt_right->parent = pt->parent;
	if (pt->parent == nil)
		root = pt_right;
	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;
	else
		pt->parent->right = pt_right;
	pt_right->left = pt;
	pt->parent = pt_right;
}
void rotateRight(RBNode*& root, RBNode* pt)	// Xoay phai
{
	RBNode* pt_left = pt->left;
	pt->left = pt_left->right;
	if (pt->left != nil)
		pt->left->parent = pt;
	pt_left->parent = pt->parent;
	if (pt->parent == nil)
		root = pt_left;
	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;
	else
		pt->parent->right = pt_left;
	pt_left->right = pt;
	pt->parent = pt_left;
}

void leftAdjust(RBNode*& root, RBNode*& x) {
	RBNode* u = x->parent->parent->right;
	if (u->color == 1) {
		x->parent->color = u->color = 0;
		x->parent->parent->color = 1;
		x = x->parent->parent;
	}
	else {
		if (x == x->parent->right) {
			x = x->parent;
			rotateLeft(root, x);
		}
		x->parent->color = 0;
		x->parent->parent->color = 1;
		rotateRight(root, x->parent->parent);
	}
}

void rightAdjust(RBNode*& root, RBNode*& x) {
	RBNode* u = x->parent->parent->left;
	if (u->color == 1) {
		x->parent->color = u->color = 0;
		x->parent->parent->color = 1;
		x = x->parent->parent;
	}
	else {
		if (x == x->parent->left) {
			x = x->parent;
			rotateRight(root, x);
		}
		x->parent->color = 0;
		x->parent->parent->color = 1;
		rotateLeft(root, x->parent->parent);
	}
}

void Insertion_FixUp(RBNode*& root, RBNode* x) {		// Sua cau truc cay sau khi chen
	while (x->parent->color == 1) {
		if (x->parent == x->parent->parent->left)
			leftAdjust(root, x);
		else
			rightAdjust(root, x);
	}
	root->color = 0;
}

RBNode* createTree(int a[], int n) {
	RBNode* root = createNode(a[0], 0, nil);
	for (int i = 1; i < n; i++) {
		Insert(root, a[i]);
	}
	return root;
}

RBNode* lookUp(RBNode* root, int key) {				
	RBNode* p = root;
	while (p->key != key && p != nil) {
		if (key > p->key)	p = p->right;
		else p = p->left;
	}
	return p;
}

int BlackHeight(RBNode* root) {
	int cnt = 1;
	RBNode* p = root;
	while (p->left != nil) {
		p = p->left;
		if (p->color == 0) cnt++;
	}
	return cnt;
}

int Height(RBNode* root) {
	if (root == nil) return 0;
	return 1 + max(Height(root->left), Height(root->right));
}

void Remove(RBNode* root, int key) {
	RBNode* z = lookUp(root, key);
	if (z == nil)	return;
	RBNode* y = (z->left == nil) || (z->right == nil) ? z : TreeSuccessor(z);
	RBNode* x = (y->left == nil) ? y->right : y->left;
	x->parent = y->parent;
	if (y->parent == nil) root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;
	if (y != z) z->key = y->key;
	if (y->color == 0)
		Del_FixUp(root, x);
	delete y;
}

RBNode* TreeSuccessor(RBNode* x) {
	RBNode* temp = x;
	while (temp->left != nil && temp->right != nil)
		temp = temp->left;
	return temp;
}

void Del_FixUp(RBNode*& root, RBNode*& x) {			// Sua cau truc cay sau khi xoa
	while ((x->color == 0) && (x != root))
		if (x == x->parent->left)
			del_leftAdjust(root, x);
		else
			del_rightAdjust(root, x);
	x->color = 0;
}

void del_leftAdjust(RBNode*& root, RBNode*& x) {
	RBNode* w = x->parent->right;
	if (w->color == 1) {
		w->color = 0;
		x->parent->color = 1;
		rotateLeft(root, x->parent);
		w = x->parent->right;
	}
	if ((w->right->color == 0) && (w->left->color == 0)) {
		w->color = 1;
		x = x->parent;
	}
	else {
		if (w->right->color == 0) {
			w->left->color = 0;;
			w->color = 1;
			rotateRight(root, w);
			w = x->parent->right;
		}
		w->color = x->parent->color;
		x->parent->color = 0;
		w->right->color = 0;
		rotateLeft(root, x->parent);
		x = root;
	}
}
void del_rightAdjust(RBNode*& root, RBNode*& x) {
	RBNode* w = x->parent->left;
	if (w->color == 1) {
		w->color = 0;
		x->parent->color = 1;
		rotateRight(root, x->parent);
		w = x->parent->left;
	}
	if ((w->left->color == 0) && (w->right->color == 0)) {
		w->color = 1;
		x = x->parent;
	}
	else {
		if (w->left->color == 0) {
			w->right->color = 0;;
			w->color = 1;
			rotateLeft(root, w);
			w = x->parent->left;
		}
		w->color = x->parent->color;
		x->parent->color = 0;
		w->left->color = 0;
		rotateRight(root, x->parent);
		x = root;
	}
}

void deleteTree(RBNode* root)
{
	if (root == nil) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
