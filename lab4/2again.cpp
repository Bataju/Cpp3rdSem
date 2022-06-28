/*Write a program that has a class with a dynamically allocated character
array as its data member. One object should contain "Engineers are" and another
should contain " Creatures of logic". Member function join() should concatenate two
strings by passing two objects as arguments. Display the concatenated string through a
member function. Use constructors to allocate and initialize the data member.
Also, write a destructor to free the allocated memory for the character array.
Make your own function for the concatenation of two strings.*/

// #include <iostream>
// #include <cstring>
// #include <stdlib.h>
// using namespace std;

// class MyString
// {
// private:
//     char *str;

// public:
//     MyString(const char *strInput)
//     {
//         cout << "Constructor invoked..." << endl;
//         str = new char[strlen(strInput)];
//         strcpy(str, strInput);
//     }

//     void concatenate(char *str1, char *str2)
//     {
//         int i = strlen(str1);
//         cout << i;
//         for (int j = 0; j < strlen(str2); j++)
//         {
//             str1[i] = str2[j];
//             i++;
//         }
//         str1[i] = '\0';
//     }

//     MyString join(MyString s1, MyString s2)
//     {
//         char *strTemp;
//         strTemp = new char [strlen(s1.str) + strlen(s2.str)];
//         strcpy(strTemp, s1.str);
//         cout << strTemp;
//         cout << 1;
//         // for(int i=0; i<strlen(strTemp) ; i++)
//         // {
//         //     (*s1).str[i] = strTemp[i];
//         // }
//         concatenate(strTemp, s2.str);
//     }

//     void displayString()
//     {
//         cout << str << endl;
//     }

//     ~MyString()
//     {
//         delete[] str;
//         cout << "Destructor invoked..." << endl;
//     }
// };

// int main()
// {
//     MyString string1("Engineers are");
//     MyString string2(" Creatures of logic");
//     MyString string3 = string3.join(string1, string2);
//     string3.displayString();
//     // string2.displayString();
//     return 0;
// }

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

class MyString
{
    private:
        char *str;
    public:
        MyString(const char* strInput)
        {
            str = new char[strlen(strInput)];
            strcpy(str, strInput);
        }

        MyString join(MyString s1, MyString s2)
        {
            char *strTemp;
            int i=0;
            strTemp = new char [strlen(s1.str)];
            strcpy(strTemp, s1.str);
            s1.str = new char [strlen(s1.str)+strlen(s2.str)+1]; //1 for null character
            for(i=0; i<strlen(strTemp); i++)
            {
                s1.str[i] = strTemp[i];
            }
            for(int j=0; j<=strlen(s2.str);j++, i++)
            {
                s1.str[i] = s2.str[j];
            }
            delete []strTemp;
            return s1;
        }

        void displayString()
        {
            cout<<str<<endl;
        }

        ~MyString()
        {
            delete []str;
        }
};

int main()
{
    MyString s1 = "Engineers are"; //parameterized constructor
    MyString s2(" Creatures of logic"); //parameterized constructor
    s1.displayString();
    s2.displayString();
    MyString s3(s1.join(s1, s2));
    s3.displayString();
    return 0;
}