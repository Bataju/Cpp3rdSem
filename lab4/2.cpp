/*Write a program that has a class with a dynamically allocated character 
array as its data member. One object should contain "Engineers are" and another 
should contain " Creatures of logic". Member function join() should concatenate two 
strings by passing two objects as arguments. Display the concatenated string through a 
member function. Use constructors to allocate and initialize the data member. 
Also, write a destructor to free the allocated memory for the character array. 
Make your own function for the concatenation of two strings.*/

#include<iostream>
#include<cstring>
using namespace std;

class Strings
{
    static int count;
    private:
        char *myString;
        int objectNumber;
    public:
        Strings(const char str[])
        {
            count++;
            objectNumber = count;
            cout<<"Constructor invoked..."<<objectNumber<<endl;
            myString = new char[strlen(str)];
            strcpy(myString, str);
        }

        Strings join(Strings str1, Strings str2)
        {
            return (strcat(str1.myString, str2.myString));
        }

        void displayString()
        {
            cout<<myString<<endl;
        }

        ~Strings()
        {
            cout<<"Destructor invoked..."<<objectNumber<<endl;
            delete []myString;
        }
};

int Strings::count = 0;

int main()
{
    Strings s1("Engineers are");
    Strings s2(" Creatures of logic");
    Strings s3(s1.join(s1, s2));
    s3.displayString();
    return 0;
}