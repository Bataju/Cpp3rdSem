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