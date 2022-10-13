#include <iostream>
#include "DoublyLinkedList.h"
#include <exception>

using namespace std;

#define printMenu                         \
    cout << "1) Add to Head" << endl      \
         << "2) Add to Tail" << endl      \
         << "3) Delete from Head" << endl \
         << "4) Delete from Tail" << endl \
         << "5) Print List" << endl       \
         << "6) Reverse K list" << endl   \
         << "7) Exit" << endl;

int main()
{
    DoublyLinkedList<int> list;

    printMenu int option;
    cout << "Enter an option: ";
    cin >> option;
    while (option != 7)
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
            cout << "Enter the value of K" << endl;
            int k;
            cin >> k;
            list.reverseList(k);
            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            break;
        }
        }
        printMenu
        cout << "Enter an option: ";
        cin >> option;
    }
}