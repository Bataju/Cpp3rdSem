/*Create a class Person and two derived classes Employee and Student, 
inherited from class Person. Now create a class Manager which is derived 
from two base classes Employee and Student. Show the use of the virtual base class.*/

#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person()
    {
        cout<<"Constructor of Person invoked.."<<endl;
    }
    void getPersonData()
    {
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }
    void showPersonData()
    {
        cout<<"Name: "<<name<<endl<<"Age: "<<age<<endl;
    }
    ~Person()
    {
        cout<<"Destructor of Person invoked.."<<endl;
    }
};

class Student: virtual public Person
{
protected:
    float gpa;
public:
    Student()
    {
        cout<<"Constructor of Student invoked.."<<endl;
    }
    void getData()
    {
        cout<<"Enter GPA: ";
        cin>>gpa;
    }
    void showData()
    {
        cout<<"GPA: "<<gpa<<endl;
    }
    ~Student()
    {
        cout<<"Destructor of Student invoked.."<<endl;
    }
};

class Employee: virtual public Person
{
protected:
    int empId;
public:
    Employee()
    {
        cout<<"Constructor of Employee invoked.."<<endl;
    }
    void getData()
    {
        cout<<"Enter employee ID: ";
        cin>>empId;
    }
    void showData()
    {
        cout<<"Employee ID: "<<empId<<endl;
    }
    ~Employee()
    {
        cout<<"Destructor of Employee invoked.."<<endl;
    }
};

class Manager: public Student, public Employee
{
private:
    float salary;
public:
    Manager()
    {
        cout<<"Constructor of Manager invoked.."<<endl;
    }
    void getData()
    {
        Student::getData();
        Employee::getData();
        cout<<"Enter salary: ";
        cin>>salary;
    }
    void showData()
    {
        Student::showData();
        Employee::showData();
        cout<<"Salary: "<<salary<<endl;
    }
    ~Manager()
    {
        cout<<"Destructor of Manager invoked.."<<endl;
    }
};

int main()
{
    Manager manager;
    cout<<"Enter data for manager.."<<endl;
    manager.getPersonData(); //possible because of virtual base class else ambiguity
    manager.getData();
    cout<<"Displaying the data for manager.."<<endl;
    manager.showPersonData();
    manager.showData();
    return 0;
}