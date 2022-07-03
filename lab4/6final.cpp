/*Create a class with a data member to hold a "serial number" for each object
created from the class. That is, the first object created will be numbered 1,
the second 2, and so on by using the basic concept of static data members.
Use static member function if it is useful in the program. Otherwise,
make a separate program that demonstrates the use of static member function.*/

#include <iostream>

using namespace std;

class DemoClass
{
private:
    int serialNumber; 

public:
    static int count;
    DemoClass()
    {
        count++;
        serialNumber = count;
        cout << "Constructor invoked for object " << serialNumber << endl;
    }
    ~DemoClass()
    {
        cout << "Destructor invoked for object " << serialNumber << endl;
    }

    static void displayNumberOfObjects()
    {
        cout << "Number of objects created: " << count << endl;
        // cout<<serialNumber<<endl; //error because static functions cannot access non static members
    }
};

int DemoClass::count = 0;

int main()
{
    DemoClass d1;
    DemoClass d2;
    DemoClass d3;
    DemoClass::displayNumberOfObjects(); // calling static function without object
    d1.displayNumberOfObjects(); //calling static function from object
    return 0;
}