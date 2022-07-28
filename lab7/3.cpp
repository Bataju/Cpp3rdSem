/*Write a program with an abstract class Student and create derive classes 
Engineering, Medicine and Science from base class Student. Create the objects 
of the derived classes and process them and access them using an array of pointers of type base class Student.*/

#include<iostream>
#include<string>
using namespace std;

class Student
{
private:
    string name;
public:
    Student()
    {
        cout<<"Constructor of Student invoked.."<<endl;
    }
    void getName()
    {
        cout<<"Enter Name: ";
        cin>>name;
    }
    void showName()
    {cout<<"Name: "<<name<<endl;}

    virtual void displayField() = 0; //pure virtual function

    virtual ~Student()
    {
        cout<<"Destructor of Student invoked.."<<endl;
    }
};

class Engineering:public Student
{
public:
    Engineering()
    {
        cout<<"Constructor of Engineering invoked.."<<endl;
    }
    void displayField() //definition for pure virtual function in derived class
    {
        cout<<"Field: Engineering"<<endl<<endl;
    }
    ~Engineering()
    {
        cout<<"Destructor of Engineering invoked.."<<endl;
    }
};

class Medicine:public Student
{
public:
    Medicine()
    {
        cout<<"Constructor of Medicine invoked.."<<endl;
    }
    void displayField()
    {
        cout<<"Field: Medicine"<<endl<<endl;
    }
    ~Medicine()
    {
        cout<<"Destructor of Medicine invoked.."<<endl;
    }
};

class Science:public Student
{
public:
    Science()
    {
        cout<<"Constructor of Science invoked.."<<endl;
    }
    void displayField()
    {
        cout<<"Field: Science"<<endl<<endl;
    }
    ~Science()
    {
        cout<<"Destructor of Science invoked.."<<endl;
    }
};

int main()
{
    Student *student[3];
    student[0] = new Engineering;
    student[1] = new Medicine;
    student[2] = new Science;

    cout<<endl<<"Taking input.."<<endl;
    cout<<"Student 1"<<endl;
    student[0]->getName(); 
    cout<<"Student 2"<<endl;
    student[1]->getName();
    cout<<"Student 3"<<endl;
    student[2]->getName();

    cout<<endl<<"Displaying the data.."<<endl;
    cout<<"Student 1"<<endl;
    student[0]->showName();
    student[0]->displayField();
    cout<<"Student 2"<<endl;
    student[1]->showName();
    student[1]->displayField();
    cout<<"Student 3"<<endl;
    student[2]->showName();
    student[2]->displayField();

    delete student[0];
    delete student[1];
    delete student[2];
    return 0;
}