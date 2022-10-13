#include <iostream>
#include <string>

using namespace std;

struct Employee
{
    string name;
    int age;
    double salary;
    void enterEmployee()
    {
        cout << "Enter the employee name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the employee age: ";
        cin >> age;
        cout << "Enter the salary: ";
        cin >> salary;
    }

    void displayEmployee() const
    {
        cout << endl << "The employee name is: " << name;
        cout << endl << "The employee age is:  " << age;
        cout << endl << "The employee's salary" << salary;

    }
};

void initialize(Employee employees[], int numEmployees)
{

    for (int i = 0; i < numEmployees; i++)
    {
        employees[i].enterEmployee();
    }
}

void displayAllStudent(Employee employees[], int numEmployees)
{
    for (size_t i = 0; i < numEmployees; i++)
    {
        employees[i].displayEmployee();
    }
}
