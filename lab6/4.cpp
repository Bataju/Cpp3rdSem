/*Write three derived classes inheriting functionality of base class person 
(should have a member function that asks to enter name and age) and with added unique features
 of student, and employee, and functionality to assign, change and delete records of student and
  employee. And make one member function for printing the address of the objects of classes (base and derived) 
  using this pointer. Create two objects of the base class and derived classes each and print the 
  addresses of individual objects. Using a calculator, calculate the address space occupied by each object 
  and verify this with address spaces printed by the program.*/

#include<iostream>
#include<cstring>
using namespace std;

class Person
{
private:
    char name[20];
    int age;
public:
    Person();
    void getData();
    void showData();
    void printAddress();
};

class Student:public Person
{
private:
    int roll;
    float gpa;
public:
    Student();
    void getData();
    void showData();
    void printAddress();
};

class Employee:public Person
{
private:
    int empId;
    char rank[20];
public:
    Employee();
    void getData();
    void showData();
    void printAddress();
};

Person::Person()
{
    strcpy(name, " ");
    age = 0;
}

void Person::getData()
{
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter age: ";
    cin>>age;
}

void Person::showData()
{
    cout<<"Name: "<<this->name<<endl
        <<"Age: "<<this->age<<endl;
}

void Person::printAddress()
{
    cout<<"Address of object of base class Person: "<<this<<endl;
}

Student::Student()
{
    roll = 0;
    gpa = 0;
}

void Student::getData()
{
    Person::getData();
    cout<<"Enter student's roll number: ";
    cin>>roll;
    cout<<"Enter student's gpa: ";
    cin>>gpa;
}

void Student::showData()
{
    Person::showData();
    cout<<"Student's roll number: "<<roll<<endl;
    cout<<"Student's GPA: "<<gpa<<endl;
}

void Student::printAddress()
{
    cout<<"Address of object of derived class Student: "<<this<<endl;
}

Employee::Employee()
{
    empId = 0;
    strcpy(rank, " ");
}

void Employee::getData()
{
    Person::getData();
    cout<<"Enter employee's ID: ";
    cin>>empId;
    cout<<"Enter employee's rank: ";
    cin>>rank;
}

void Employee::showData()
{
    Person::showData();
    cout<<"Employee's ID: "<<empId<<endl;
    cout<<"Employee's rank: "<<rank<<endl;
}

void Employee::printAddress()
{
    cout<<"Address of object of derived class Employee: "<<this<<endl;
}

int main()
{
    Person p1, p2;
    Student s1, s2;
    Employee e1, e2;
    cout<<"Addresses of objects of base and derived classes."<<endl;
    p1.printAddress();
    p2.printAddress();
    s1.printAddress();
    s2.printAddress();
    e1.printAddress();
    e2.printAddress();
    cout<<"Size occupied by the objects of base and derived classes. "<<endl;
    cout<<"Size of objects of class Person(p1 and p2): "<<sizeof(p1)<<" and "<<sizeof(p2)<<endl;
    cout<<"Size of objects of class Student(s1 and s2): "<<sizeof(s1)<<" and "<<sizeof(s2)<<endl;
    cout<<"Size of objects of class Employee(e1 and e2): "<<sizeof(e1)<<" and "<<sizeof(e2)<<endl;
}