/*Write three derived classes inheriting functionality of base class person
(should have a member function that asks to enter name and age) and with added
unique features of student, and employee, and functionality to assign, change
and delete records of student and employee. And make one member function for
printing the address of the objects of classes (base and derived) using this
pointer. Create two objects of the base class and derived classes each and print
the addresses of individual objects. Using a calculator, calculate the address space
occupied by each object and verify this with address spaces printed by the program.*/

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();
    void getData();
    void showData();
    void printAddress();
};

class Student : public Person
{
private:
    int rollNo;
    int grade;

public:
    Student();
    void getData();
    void showData();
    void printAddress();
};

class Employee : public Person
{
private:
    int employeeId;
    string position;

public:
    Employee();
    void getData();
    void showData();
    void printAddress();
};

Person::Person()
{
    name = " ";
    age = 0;
}
void Person::getData()
{
    cout << "Enter your name: ";
    cin >> this->name;
    cout << "Enter your age: ";
    cin >> this->age;
}
void Person::showData()
{
    cout << "Name: ";
    cout << this->name << endl;
    cout << "Age: ";
    cout << this->age << endl;
}
void Person::printAddress()
{
    cout << "Address of object of base class Person: " << this << endl;
}

Student::Student()
{
    rollNo = 0;
    grade = 0;
}
void Student::getData()
{
    Person::getData();
    cout << "Enter student's roll number: ";
    cin >> this->rollNo;
    cout << "Enter student's grade: ";
    cin >> this->grade;
}
void Student::showData()
{
    Person::showData();
    cout << "Roll number: ";
    cout << this->rollNo << endl;
    cout << "Grade: ";
    cout << this->grade << endl;
}
void Student::printAddress()
{
    cout << "Address of object of derived class Student: " << this << endl;
}

Employee::Employee()
{
    employeeId = 0;
    position = " ";
}
void Employee::getData()
{
    Person::getData();
    cout << "Enter employee's id: ";
    cin >> this->employeeId;
    cout << "Enter employee's position: ";
    cin >> this->position;
}
void Employee::showData()
{
    Person::showData();
    cout << "Employee id: ";
    cout << this->employeeId << endl;
    cout << "Position: ";
    cout << this->position << endl;
}
void Employee::printAddress()
{
    cout << "Address of object of derived class Employee: " << this << endl;
}

int main()
{
    Person p1, p2;   // base
    Student s1, s2;  // derived
    Employee e1, e2; // derived

    cout << "Enter data for student 1.." << endl;
    s1.getData();
    cout << "Enter data for student 2.." << endl;
    s2.getData();
    cout << "Enter data for employee 1.." << endl;
    e1.getData();
    cout << "Enter data for employee 2.." << endl;
    e2.getData();

    cout << "Data for student 1.." << endl;
    s1.showData();
    cout << "Data for student 2.." << endl;
    s2.showData();
    cout << "Data for employee 1.." << endl;
    e1.showData();
    cout << "Data for employee 2.." << endl;
    e2.showData();

    cout << "Printing the addresses.." << endl;
    p1.printAddress();
    p2.printAddress();
    s1.printAddress();
    s2.printAddress();
    e1.printAddress();
    e2.printAddress();
    return 0;
}