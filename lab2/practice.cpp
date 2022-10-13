#include <iostream>
#include <string>
using namespace std;

struct Student
{

    int regNo;
    string name;

    void enterStudentData()
    {
        cout << "---------------------------------------------\n"
             << endl;
        cout << "Enter Reg No. : ";
        cin >> regNo;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "---------------------------------------------\n"
             << endl;
    }

    void displayStudent()
    {

        cout << regNo
             << "\t\t" << name << endl;
    }
};

void initialize(Student students[], int size)
{
    for (int i = 0; i < size; i++)
        students[i].enterStudentData();
}
void displayAllStudents(Student students[], int size)
{
    cout << endl
         << "-----------------------------------------------\n";
    cout << "\tList of Students\n";
    cout << "-----------------------------------------------\n";

    cout << "-----------------------------------------------\n";
    cout << "Reg No\t\tName" << endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; i++)
        students[i].displayStudent();

    cout << "-----------------------------------------------\n";
}

int main()
{
    int size;
    cout << "Enter the number of students: ";
    cin >> size;

    Student *students = new Student[size];

    initialize(students, size);

    displayAllStudents(students, size);
}