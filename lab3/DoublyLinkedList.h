#pragma once
#include "DLLNode.h"
#include <iostream>
#include <exception>

using namespace std;

template <class T>
class DoublyLinkedList
{
    using dll_node = DLLNode<T>;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }
    void insertNodeAtHead(const T &);                 
    void insertNodeAtTail(const T &);                 
    void printList() const;                           
    void deleteNode(const T &);                       
    T deleteNodeAtHead();                             
    T deleteNodeAtTail();                             
    bool isInList(const T &) const;                   
    bool isEmpty() const { return head == nullptr; }; 
    void reverseList(const T &k);
    void makeCircular();
    void removeCircular();
    bool isCircular() const;

protected:
    dll_node *head, *tail;
};

template <class T>
void DoublyLinkedList<T>::deleteNode(const T &elem)
{
    // if list is not empty
    if (isEmpty())
    {
        cout << "The list is empty" << endl;
    }
    else
    {
        // if element is at the start and there is only one node
        if (head == tail && elem == head->data)
        {
            delete head;
            head = tail = nullptr;
        }
        // if elem is at start and there are more than one nodes
        else if (head->data == elem)
        {
            dll_node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        else
        {
            dll_node *temp = head->next;
            while (temp != nullptr && temp->data != elem)
            {
                temp = temp->next;
            }

            if (temp != nullptr)
            {
                // if elem being removed is the last element
                if (temp == tail)
                {
                    tail = temp->prev;
                }
                temp->prev->next = temp->next;
                delete temp;
            }
        }
    }
}

template <class T>
void DoublyLinkedList<T>::insertNodeAtHead(const T &elem)
{
   
    // if list was empty before this
    if (tail == nullptr)
    {
        tail = head =  new DLLNode(elem);
        return;
    } else {
        head = new dll_node(elem, head);
    }
}

template <class T>
void DoublyLinkedList<T>::insertNodeAtTail(const T &elem)
{
    if (tail != nullptr)
    {

        tail =  new DLLNode<T>(elem, nullptr, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new dll_node(elem);
}

template <class T>
T DoublyLinkedList<T>::deleteNodeAtHead()
{
    dll_node *nodeToDelete = new dll_node();
    nodeToDelete = head;
    T valDeleted = head->data;

    // if list only has one node
    if (head == tail)
    {
        // there was no value
        head = tail = nullptr;
    }
    else
    {

        head = head->next;
        head->prev = nullptr;
    }
    delete nodeToDelete;
    return valDeleted;
}

template <class T>
T DoublyLinkedList<T>::deleteNodeAtTail()
{

    T valDeleted = tail->data;
    if (head == tail)
    {
        // there was no value
        delete head;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return valDeleted;
}
template <class T>
void DoublyLinkedList<T>::printList() const
{

    if (isEmpty())
    {
        cout << "The list is empty" << endl;
        return;
    }
    else
    {
        for (dll_node *temp = head; temp != nullptr;
             temp = temp->next)
        {
            cout << temp->data << " ";
        }
    }
}

template <class T>
bool DoublyLinkedList<T>::isInList(const T &elem) const
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        dll_node *temp = head;
        while (temp != nullptr && temp->data != elem)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


template<class T>
void DoublyLinkedList<T>::reverseList(const T &k) {

    dll_node *temp = head;
    // lets say we get 3
    dll_node *start = head;

    for (int i = 1; i < k; i++) {
        temp = temp->next;
    }
    // temp is now pointing to the kth node

    for (int i = 1; i <= k/2; i++) {
        // swap last and first
        dll_node *temp2 = new dll_node(temp->data);
        temp->data = start->data;
        start->data = temp2->data;

        start = start->next;
        temp = temp->prev;
        // move the start to the next start
        // move end to the previous end
    

    }
    
    

}


template<class T>
void DoublyLinkedList<T>::makeCircular() {
    head->prev = tail;
    tail->next = head;
}

template<class T>
void DoublyLinkedList<T>::removeCircular() {
    head->prev = nullptr;
    tail->next = nullptr;
}

template <class T>
bool DoublyLinkedList<T>::isCircular() const {
    if (tail->next == head && head->prev == tail) {
        return true;
    } else {
        return false;
    }
}