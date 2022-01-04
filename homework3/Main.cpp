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
    printList(list);                            // In danh sach demo
    cout << "\naddHead(5):\n ";
    addHead(list, createNode(5));               // Test ham addHead
    printList(list);                            // In danh sach
    cout << "\naddTail(6):\n ";
    addTail(list, createNode(6));               // Test ham addTail
    printList(list);
    cout << "\naddAfter(7,3):\n ";
    addAfter(list, createNode(7), 3);           // Test ham addAfter
    printList(list);
    cout << "\nremoveHead():\n ";
    removeHead(list);                           // Test ham removeHead
    printList(list);
    cout << "\nremoveTail():\n ";
    removeTail(list);                           // Test ham removeTail
    printList(list);
    cout << "\nremoveAfter(3):\n ";
    removeAfter(list, 3);                       // Test ham removeAfter
    printList(list);

    while (list->pTail) {                       // Xoa danh sach
        removeTail(list);
    }


    delete list;
}
