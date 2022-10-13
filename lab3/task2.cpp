#include <iostream>

#include "DoublyLinkedList.h"

using namespace std;

#define printMenu                         \
    cout << "1) Add to Head" << endl      \
         << "2) Add to Tail" << endl      \
         << "3) Delete from Head" << endl \
         << "4) Delete from Tail" << endl \
         << "5) Print List" << endl       \
         << "6) Make Cycle" << endl   \
         << "7) Detect Cycle" << endl \
         << "8) Remove Cycle" << endl \
         << "9) Exit" << endl;

int main() {
 
     DoublyLinkedList<int> list;

    printMenu int option;
    cout << "Enter an option: ";
    cin >> option;
    while (option != 9)
    {
        switch (option)
        {
        case 1:
        {
            int value;
            cout << "Enter the value: ";
            cin >> value;
            list.insertNodeAtHead(value);
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter the value: ";
            cin >> value;
            list.insertNodeAtTail(value);
            break;
        }
        case 3:
        {
            list.deleteNodeAtHead();
            break;
        }
        case 4:
        {
            list.deleteNodeAtTail();
            break;
        }
        case 5:
        {
            list.printList();
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "Make cycle" << endl;
            list.makeCircular();
            break;
        }
        case 7:
        {
            cout << "is cycle circular? " << endl;
            cout << ((list.isCircular()) ? "true" : "false") << endl;
            break;
        }
        default:
        {
            list.removeCircular();
            break;
        }
        }
        printMenu
        cout << "Enter an option: ";
        cin >> option;
    }

}