#pragma once

struct CNode {
    int data;
    CNode* next;
};
struct CList {
    CNode* pTail;
};


CNode* createNode(int data);
void addHead(CList* list, CNode* node);
void removeHead(CList* list);
void addTail(CList* list, CNode* node);
void removeTail(CList* list);
bool addAfter(CList* list, CNode* node, int val);
bool removeAfter(CList* list, int val);
void printList(CList* list);
