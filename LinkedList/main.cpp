#include "DoubleLinkedList.h"

int main()
{
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);

    myLinkedList.addAtTail(3);

    myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3

    cout << myLinkedList.get(1) << endl; // return 2

    myLinkedList.deleteAtIndex(1); // now the linked list is 1->3

    cout << myLinkedList.get(1) << endl;

    cout << "ffff..." << endl;
    return 0;
}