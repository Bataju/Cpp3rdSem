#include <iostream>
using namespace std;

class MyClass
{
private:
    int *intPtr;
public:
    MyClass(int num=0)
    {
        cout<<"Constructor invoked..."<<endl;
        intPtr = new int(num);
    }

    void setInt(int inputInt)
    {
        *intPtr = inputInt;
    }

    MyClass& operator =(MyClass& obj2)
    {
        if(this != &obj2) //checking for self assignment
            *intPtr = *(obj2.intPtr);
        return *this; //returning reference so that we can cascade obj1=ob2=obj3
    }

    void display()
    {
        cout<<"The integer currently stored in the integer pointer: "<<*intPtr<<endl;
    }

    ~MyClass()
    {
        cout<<"Destructor invoked..."<<endl;
        delete intPtr;
    }
};

int main()
{
    MyClass obj1(5);
    MyClass obj2(8);
    cout<<"BEFORE ASSIGNMENT..."<<endl;
    obj1.display();
    obj2.display();
    obj2=obj1;
    cout<<"AFTER ASSIGNMENT..."<<endl;
    obj1.display();
    obj2.display();
    obj2.setInt(99);
    cout<<"AFTER CHANGING THE VALUE OF OBJECT 2..."<<endl;
    obj1.display();
    obj2.display();
    return 0;
}

//try this code without overloading the assignment operator.
//comment that part out 
//the default assignment operator will just allow the members (intPtr)
//of both the objects to point to the same memory location 
//and hence change in any one of them will result in the change in other as well
//so we need to overload the assignment operator to overcome this problem
//but once we overload the assignment operator, we assign the values in
//(intPtr), not the memory itself
