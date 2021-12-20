#pragma once

struct RBNode {
	int key;
	bool color;
	RBNode* parent;
	RBNode* left;
	RBNode* right;
};

extern RBNode* nil;
RBNode* createNode(int key, int color, RBNode* nil);
void Insert(RBNode*& root, int key);
void rotateLeft(RBNode*& root, RBNode* pt);
void rotateRight(RBNode*& root, RBNode* pt);
void leftAdjust(RBNode*& root, RBNode*& x);
void rightAdjust(RBNode*& root, RBNode*& x);
void Insertion_FixUp(RBNode*& root, RBNode* x);
RBNode* createTree(int a[], int n);
RBNode* lookUp(RBNode* root, int key);
int BlackHeight(RBNode* root);
int Height(RBNode* root);
void Remove(RBNode* root, int key);
RBNode* TreeSuccessor(RBNode* x);
void Del_FixUp(RBNode*& root, RBNode*& x);
void del_leftAdjust(RBNode*& root, RBNode*& x);
void del_rightAdjust(RBNode*& root, RBNode*& x);
void deleteTree(RBNode* root);