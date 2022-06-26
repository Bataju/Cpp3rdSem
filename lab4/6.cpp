/*Create a class with a data member to hold a "serial number" for each object 
created from the class. That is, the first object created will be numbered 1, 
the second 2, and so on by using the basic concept of static data members. 
Use static member function if it is useful in the program. Otherwise, 
make a separate program that demonstrates the use of static member function.*/

#include<iostream>
using namespace std;

class DemoSerialNumber
{
    static int count;
    private:
        int nonstaticVariable;
        int serialNumber;
    public:
        DemoSerialNumber()
        {
            count++;
            serialNumber = count;
            cout<<"Constructor invoked... "<<serialNumber<<endl;
        }

        static void staticFunctionToDisplayCount()
        {
            cout<<"Displaying static data member count..."<<count<<endl;//static member functions can only access static data members
        }

        ~ DemoSerialNumber()
        {
            cout<<"Destructor invoked..."<<serialNumber<<endl;
        }
};

int DemoSerialNumber::count = 0;

int main()
{
    DemoSerialNumber d1;
    DemoSerialNumber::staticFunctionToDisplayCount();
    DemoSerialNumber d2;
    DemoSerialNumber::staticFunctionToDisplayCount();
    return 0;
}