#include "employee.h"

int main()
{
    int size;
    cout << "Enter the number of employees: ";
    cin >> size;
    Employee *employees = new Employee[size];
    initialize(employees, size);
    displayAllStudent(employees, size);
}