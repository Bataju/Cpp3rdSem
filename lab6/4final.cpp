/*Write three derived classes inheriting functionality of base class person
(should have a member function that asks to enter name and age) and with added
unique features of student, and employee, and functionality to assign, change
and delete records of student and employee. And make one member function for
printing the address of the objects of classes (base and derived) using this
pointer. Create two objects of the base class and derived classes each and print
the addresses of individual objects. Using a calculator, calculate the address space
occupied by each object and verify this with address spaces printed by the program.*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected: // so that derived classes can change it
    char name[20];
    int age;

public:
    Person() : name(""), age(0) {} // initializer list
    void getData();
    void showData();
    void updateData();
    void deleteData();
    void printAddress();
};

class Student : public Person
{
private:
    float gpa;

public:
    Student() : gpa(0.0) {}
    void getData();
    void updateData();
    void deleteData();
    void showData();
    void printAddress();
};

class Employee : public Person
{
private:
    int employeeId;

public:
    Employee() : employeeId(0) {}
    void getData();
    void showData();
    void updateData();
    void deleteData();
    void printAddress();
};

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
void Person::updateData()
{
    cout << "Enter new name: ";
    cin >> name;
    cout << "Enter new age: ";
    cin >> age;
}
void Person::deleteData()
{
    strcpy(name, "");
    age = 0;
}
void Person::printAddress()
{
    cout << "Address of object of base class Person: " << this << endl;
}

void Student::getData()
{
    Person::getData();
    cout << "Enter student's GPA: ";
    cin >> this->gpa;
}
void Student::showData()
{
    Person::showData();
    cout << "GPA: ";
    cout << this->gpa << endl;
}
void Student::updateData()
{
    Person::updateData();
    cout << "Enter new GPA: ";
    cin >> gpa;
}
void Student::deleteData()
{
    Person::deleteData();
    gpa = 0.0;
}
void Student::printAddress()
{
    cout << "Address of object of derived class Student: " << this << endl;
}

void Employee::getData()
{
    Person::getData();
    cout << "Enter employee's id: ";
    cin >> this->employeeId;
}
void Employee::showData()
{
    Person::showData();
    cout << "Employee id: ";
    cout << this->employeeId << endl;
}
void Employee::updateData()
{
    Person::updateData();
    cout << "Enter new employee ID: ";
    cin >> employeeId;
}
void Employee::deleteData()
{
    Person::deleteData();
    employeeId = 0;
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
    char choice = 'n';
    
    //this can be done for employee as well but we don't do that here
    cout << "Enter data for student 1.." << endl;
    s1.getData();
    cout << endl<< "Data for student 1.." << endl;
    s1.showData();
    cout<<endl<<"Do you want to UPDATE the data for estudiante? ['y' / 'n'] ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        s1.updateData();
        cout << endl<< "Data for student 1.." << endl;
        s1.showData();
    }

    choice = 'n';
    cout<<endl<<"Do you want to DELETE the data for estudiante? ['y' / 'n'] ";
    cin>>choice;
    if(choice == 'y' || choice == 'Y')
    {
        s1.deleteData();
        s1.showData();
    }

    cout << endl << "Printing the addresses.." << endl;
    p1.printAddress();
    p2.printAddress();
    s1.printAddress();
    s2.printAddress();
    e1.printAddress();
    e2.printAddress();

    cout << endl
         << "The number of bytes occupied by the objects..." << endl;
    cout << "p1: " << sizeof(p1) << endl;
    cout << "p2: " << sizeof(p2) << endl;
    cout << "s1: " << sizeof(s1) << endl;
    cout << "s2: " << sizeof(s2) << endl;
    cout << "e1: " << sizeof(e1) << endl;
    cout << "e2: " << sizeof(e2) << endl;
    return 0;
}