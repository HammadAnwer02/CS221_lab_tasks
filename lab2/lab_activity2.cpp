
#include "students.h"

int main()
{

    int size;
    cout << "Enter the number of students: ";
    cin >> size;

    Student *students = new Student[size];

    initialize(students, size);
    displayAllAge14(students, size);
    displayAllEvenReg(students, size);
    cout << "The reg to search: ";
    int regToSearch;
    cin >> regToSearch;
    displayAllWithReg(students, size, regToSearch);
}