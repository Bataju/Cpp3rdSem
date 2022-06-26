/*Write a class that can store Department ID and Department Name 
with constructors to initialize its members. Write destructor member in the same class 
and display the message "Object n goes out of the scope". Your program should be made 
such that it should show the order of constructor and destructor invocation.*/

#include<iostream>
#include<cstring>
using namespace std;

class Department
{
    static int count;//static data member

    private:
        int departmentId;
        char *departmentName;
        int position;

    public:
        Department(int deptId, const char *deptName)
        {
            count++;
            position = count;
            cout<<count<<". Constructor invoked..."<<endl;
            departmentId = deptId;
            departmentName = new char[20];
            strcpy(departmentName , deptName);
        }

        void showData()
        {
            cout<<"Department Id: "<<departmentId<<endl<<"Department Name: "<<departmentName<<endl;
        }

        ~ Department()
        {
            delete []departmentName;
            cout<<"Object "<<position<<" goes out of scope"<<endl;
        }
};

int Department::count = 0;

int main()
{
    Department d1(1001, "Snacks");
    Department d2(1002, "Drinks");
    Department d3(1003, "Dinner");
    return 0;
}

