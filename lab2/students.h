#include <iostream>
#include <string>


using namespace std;

struct Student
{

    int regNo;
    string name;
    int age;
    string address;


    // constructor
    Student() {
        age = 0;
        regNo = 0;
        name = "";
        address = "";
    }

    // for validation for correct age
    bool isValidAge(int age)
    {
        return (age >= 11 & age <= 14);
    }

    // enter data for single student
    void enterStudentData()
    {
        cout << "---------------------------------------------\n"
             << endl;
        cout << "Enter Reg No. : ";
        cin >> regNo;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the students age: ";
        do
        {
            cin >> age;
        } while (!isValidAge(age));
        cout << "Enter the address of the student: ";
        cin.ignore();
        getline(cin, address);
        cout << "---------------------------------------------\n"
             << endl;
    }

    // display data for a single student
    void displayStudent()
    {

        cout << regNo
             << "\t\t" << name << "\t\t" << age << "\t\t" << address << endl;
    }
};

// enter data for all students
void initialize(Student students[], int size)
{
    for (int i = 0; i < size; i++)
        students[i].enterStudentData();
}

// display data for all students
void displayAllStudents(Student students[], int size)
{
    cout << endl
         << "-----------------------------------------------\n";
    cout << "\tList of Students\n";
    cout << "-----------------------------------------------\n";

    cout << "-----------------------------------------------\n";
    cout << "Reg No\t\tName\t\tAge\t\tAddress" << endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; i++)
        students[i].displayStudent();

    cout << "-----------------------------------------------\n";
}

// display to all students age 14
void displayAllAge14(Student students[], int size)
{
    cout << endl
         << "-----------------------------------------------\n";
    cout << "\tList of Students Age 14\n";
    cout << "-----------------------------------------------\n";

    cout << "-----------------------------------------------\n";
    cout << "Reg No\t\tName\t\tAge\t\tAddress" << endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; i++)
        if (students[i].age == 14)
        {
            students[i].displayStudent();
        }

    cout << "-----------------------------------------------\n";
}

void displayAllEvenReg(Student students[], int size) {
    cout << endl
         << "-----------------------------------------------\n";
    cout << "\tList of Students with Even Reg No\n";
    cout << "-----------------------------------------------\n";
     cout << "-----------------------------------------------\n";
    cout << "Reg No\t\tName\t\tAge\t\tAddress" << endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; i++)
        if (students[i].regNo % 2 == 0)
        {
            students[i].displayStudent();
        }
}

void displayAllWithReg(Student students[], int size, int regToSearch) {
     cout << endl
         << "-----------------------------------------------\n";
    cout << "\tList of Students with Reg No\n";
    cout << "-----------------------------------------------\n";
     cout << "-----------------------------------------------\n";
    cout << "RegNo\t\tName\t\tAge\t\tAddress" << endl;
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < size; i++)
        if (students[i].regNo == regToSearch)
        {
            students[i].displayStudent();
        }
}