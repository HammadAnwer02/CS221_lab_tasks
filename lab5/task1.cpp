/**
 * @file task1.cpp
 * @author Hammad Anwer 2021189
 * @brief
 * @version 0.1
 * @date 2022-10-13
 * @copyright Copyright (c) 2022
 *
 */

#include "Queue.h"
#define read(type, var) type var; cin >> var;
using namespace std;


void menu() {
    cout << "Choose one of the following options: \n\n";
    cout << "1)Enqueue\n";
    cout << "2)Dequeue\n";
    cout << "3)Print Value\n";
    cout << "4)Reverse K elements in the queue\n";
    cout << "5)InterLeave\n";
    cout << "6)Exit\n\n";
}

int main()
{
    Queue<int> q;
    menu();

    cout << "Your option is: ";
    read(int, option)
    while (option != 6) {
        switch(option) {
            case 1: {
                cout << "\nEnter the value to insert: ";
                read(int, value);

                q.enqueue(value);
                break;
            }
            case 2: {
                try
                {
                    q.dequeue();
                      break;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                break;
                }
            }
            case 3: 
            {
                q.printQueue();
                break;
            }
            case 4: {
               try
               {
                cout << "Enter the value of k: ";
                read(int, k);
                    q.reverseKElements(k);
               }
               catch(const std::exception& e)
               {
                std::cerr << e.what() << '\n';
               }
               
            }
            case 5: {
                q.interLeave();
                break;
            }
            case 6: {
                break;
            }

        };
        menu();
        cout << "Your option is: ";
        cin>> option;
    }
    
     return 0;
}