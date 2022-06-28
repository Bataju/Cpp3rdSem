/*Write a class that can store Department ID and Department Name 
with constructors to initialize its members. Write destructor member in the same class 
and display the message "Object n goes out of the scope". Your program should be made 
such that it should show the order of constructor and destructor invocation.*/

#include<iostream>
#include<cstring>

using namespace std;

class Department
{
    private:
        int departmentId;
        char departmentName[20];
    public:
        Department(int deptId = 0, const char deptName[] = "Null") //constructor
        {
            departmentId = deptId;
            strcpy(departmentName, deptName);
            cout<<"Object "<<departmentId<<" created.."<<endl;
        }

        void display()
        {
            cout<<"Department ID: "<<departmentId<<endl<<"Department name: "<<departmentName<<endl;
        }

        ~Department()
        {
            cout<<"Object "<<departmentId<<" goes out of scope.."<<endl;
        }
};

int main()
{
    Department d1;//default costructor
    Department d2(1001, "Snacks");//parameterized constructor
    Department d3 = {1002, "Drinks"};//parameterized constructor
    d1.display();
    d2.display();
    d3.display();
    return 0;
}