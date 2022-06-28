/*Write a program that has a class with a dynamically allocated character
array as its data member. One object should contain "Engineers are" and another
should contain " Creatures of logic". Member function join() should concatenate two
strings by passing two objects as arguments. Display the concatenated string through a
member function. Use constructors to allocate and initialize the data member.
Also, write a destructor to free the allocated memory for the character array.
Make your own function for the concatenation of two strings.*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

class MyString
{
private:
    char *str;

public:
    MyString(const char *strInput)
    {
        cout << "Constructor invoked..." << endl;
        str = new char[strlen(strInput)];
        strcpy(str, strInput);
    }

    void concatenate(char *str1, char *str2)
    {
        int i = strlen(str1);
        cout << i;
        for (int j = 0; j < strlen(str2); j++)
        {
            str1[i] = str2[j];
            i++;
        }
        str1[i] = '\0';
    }

    MyString join(MyString s1, MyString s2)
    {
        char *strTemp;
        strTemp = new char [strlen(s1.str) + strlen(s2.str)];
        strcpy(strTemp, s1.str);
        cout << strTemp;
        cout << 1;
        // for(int i=0; i<strlen(strTemp) ; i++)
        // {
        //     (*s1).str[i] = strTemp[i];
        // }
        concatenate(strTemp, s2.str);
    }

    void displayString()
    {
        cout << str << endl;
    }

    ~MyString()
    {
        delete[] str;
        cout << "Destructor invoked..." << endl;
    }
};

int main()
{
    MyString string1("Engineers are");
    MyString string2(" Creatures of logic");
    MyString string3 = string3.join(string1, string2);
    string3.displayString();
    // string2.displayString();
    return 0;
}