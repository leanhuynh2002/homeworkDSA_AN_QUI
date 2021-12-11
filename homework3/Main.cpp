#include <iostream>
#include "CircularLinkedList.h"
using namespace std;

int main() {
    CList* list = new CList;
    list->pTail = NULL;
    for (int i = 1; i < 5; i++) {
        addTail(list, createNode(i));
    }

    cout << "List:\n ";
    printList(list);
    cout << "\naddHead(5):\n ";
    addHead(list, createNode(5));
    printList(list);
    cout << "\naddTail(6):\n ";
    addTail(list, createNode(6));
    printList(list);
    cout << "\naddAfter(7,3):\n ";
    addAfter(list, createNode(7), 3);
    printList(list);
    cout << "\nremoveHead():\n ";
    removeHead(list);
    printList(list);
    cout << "\nremoveTail():\n ";
    removeTail(list);
    printList(list);
    cout << "\nremoveAfter(3):\n ";
    removeAfter(list, 3);
    printList(list);

    while (list->pTail) {
        removeTail(list);
    }


    delete list;
}