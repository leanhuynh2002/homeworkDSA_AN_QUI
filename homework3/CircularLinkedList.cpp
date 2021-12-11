#include <iostream>
#include "CircularLinkedList.h"
using namespace std;


CNode* createNode(int data) {
    CNode* node = new CNode;
    node->data = data;
    node->next = NULL;
    return node;
}

void addHead(CList* list, CNode* node){
    if (!list->pTail) {
        list->pTail = node;
        node->next = node;
    }
    else {
        node->next = list->pTail->next;
        list->pTail->next = node;
    }
}

void removeHead(CList* list) {
    if (list->pTail && list->pTail->next == list->pTail) {
        delete list->pTail;
        list->pTail = NULL;
    }
    else if (list->pTail) {
        CNode* temp = list->pTail->next;
        list->pTail->next = temp->next;
        delete temp;
    }
}

void addTail(CList* list, CNode* node) {
    if (!list->pTail) {
        list->pTail = node;
        node->next = node;
    }
    else {
        node->next = list->pTail->next;
        list->pTail->next = node;
        list->pTail = node;
    }
}

void removeTail(CList* list) {
    if (list->pTail && list->pTail->next == list->pTail) {
        delete list->pTail;
        list->pTail = NULL;
    }
    else if (list->pTail) {
        CNode* temp = list->pTail->next;
        while (temp->next != list->pTail) {
            temp =temp->next;
        }
        temp->next = list->pTail->next;
        delete list->pTail;
        list->pTail = temp;
    }
}

bool addAfter(CList* list, CNode* node, int val) {
    CNode* ptr = list->pTail->next;
    while (ptr->data != val && ptr != list->pTail) {
        ptr = ptr->next;
    }
    if (ptr->data == val) {
        node->next = ptr->next;
        ptr->next = node;
        return 1;
    }
    else return 0;
}

bool removeAfter(CList* list, int val) {
    CNode* ptr = list->pTail->next;
    while (ptr->data != val && ptr != list->pTail) {
        ptr = ptr->next;
    }
    if (ptr->data == val) {
        CNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return 1;
    }
    else return 0;
}

void printList(CList* list) {
    CNode* ptr = list->pTail;
    do {
        ptr = ptr->next;
        cout << ptr->data << "   ";
    } while (ptr != list->pTail);
}



