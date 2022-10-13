/**
 * @file Queue.h
 * @author Hammad Anwer 2021189
 * @brief Contains the class that stores each node of the queue along with the Queue itself, the queue has been made generic to store data of any type,
 *
 * @version 0.1
 * @date 2022-10-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <exception>

using namespace std;

template <class T>
class QueueNode
{
public:
    T value;
    QueueNode *prev, *next;
    QueueNode(T val = 0, QueueNode *p = nullptr, QueueNode *n = nullptr)
    {
        value = val;
        prev = p;
        next = n;
    }
};

template <class T>
class Queue
{
private:
    int count;
    QueueNode<T> *head, *tail;

public:
    Queue()
    {
        head = tail = nullptr;
        count = 0;
    }


    void interLeave() {
        int half = count/ 2;
        int counter = 0;
        QueueNode<T> *halfwayNode = head;
        while (counter != half) {
            if (halfwayNode!= nullptr){
            halfwayNode = halfwayNode->next;
            counter++;

            } else {
                throw invalid_argument("Can't be swapped");
            }
        }
        QueueNode<T> *start = head;
        while (halfwayNode->next != nullptr) {
            QueueNode<T> *temp = halfwayNode;
            halfwayNode = halfwayNode->next;
            start->next->prev = temp;
            temp->prev = start;
            temp->next = start->next;
            start->next = temp;
            start = start->next->next;
        }
        start->next = halfwayNode;

    }
    void reverseKElements(int k) {
        int counter = 0;
        QueueNode<T> *temp = head;
        while (counter < k - 1) {
            if (temp != nullptr) {
            temp = temp->next;
            counter++;

            } else {
                throw invalid_argument("Queue can't be reversed with this value of k");
            }
        }

        QueueNode<T> *start = head;
        while (temp != start && temp->next != start) {
            swap(temp->value, start->value);
            start = start->next;
            temp = temp->prev;
        }

    }
    void enqueue(T val)
    {
        // if no node in the list;
        if (head == nullptr)
        {
            QueueNode<T> *newNode = new QueueNode(val);
            head = tail = newNode;
        }
        else
        {
            QueueNode<T> *newNode = new QueueNode(val, tail);
            tail->next = newNode;
            tail = newNode;
        }
        count++;
        return;
    }
    void dequeue()
    {
        if (head == tail)
        {
            QueueNode<T> *temp = head;
            head = tail = nullptr;
            delete temp;
        }
        else if (head == nullptr)
        {
            throw invalid_argument("ist is aleady empty can't dequeue further");
        }
        else
        {
            // remove from head
            QueueNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    void printQueue()
    {
        if (head == nullptr)
        {
            cout << "List is empty";
        }
        else
        {
            QueueNode<T> *temp = head;
            cout << "\nThe queue elements is/are: ";
            while (temp != nullptr)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    ~Queue()
    {
        QueueNode<T> *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
            dequeue();
        }
    }
};
