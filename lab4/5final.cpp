/*Write a program that illustrates the following relationship and comment on them.

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function*/

#include <iostream>

using namespace std;

class DemoClass
{
private:
    int randomNumber;

public:
    DemoClass()
    {
        cout << "Constructor invoked..." << endl;
        cout << "Enter a number and I'll remember it: ";
        cin >> randomNumber;
    }

    void nonConstantFunc()
    {
        cout << "The number you entered was: " << randomNumber << endl;
    }

    void constantFunc() const
    {
        cout << "The number you entered was: " << randomNumber << endl;
    }

    ~DemoClass()
    {
        cout << "Destructor invoked..." << endl;
    }
};

int main()
{
    DemoClass d1;         // non constant object
    const DemoClass d2;   // constant object
    d1.nonConstantFunc(); // calling non constant function from non constant object
    d1.constantFunc();    // calling constant function from non constant object
    // d2.nonConstantFunc(); //error //calling non constant function from constant object
    d2.constantFunc(); // calling constant function from constant object
    return 0;
}