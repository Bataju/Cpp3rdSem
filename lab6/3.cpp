/*Create a class called Musicians to contain three methods string(), wind(), and perc().
Each of these methods should initialize a string array to contain the following instruments
-  veena, guitar, sitar, sarod and mandolin under string()
-  flute, clarinet saxophone, nadhaswaram, and piccolo under wind()
-  tabla, mridangam, bangos, drums and tambour under perc()
It should also display the contents of the arrays that are initialized.
Create a derived class called TypeIns to contain a method called get() and show().
The get() method must display a  menu as follows
Type of instruments to be displayed
a.  String instruments
b.  Wind instruments
c.  Percussion instruments
The show() method should display the relevant detail according to our choice.
The base class variables must be accessible only to their derived classes.*/

#include <iostream>
#include <string>
using namespace std;

class Musicians
{
private:
    string stringArray[5];
    char inputArray[15][15] = {"veena", "guitar", "sitar", "sarod", "mandolin", "flute", "clarinet", "saxophone", "nadhaswaram", "piccolo", "tabla", "mridangam", "bangos", "drums", "tambour"};

public:
    void string()
    {
        for (int i = 0; i < 5; i++)
        {
            stringArray[i] = inputArray[i];
        }
        cout << "Displaying the contents of the array initialized.." << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << stringArray[i];
            if(i < 4){cout<< ", ";}//only for the first 4 items
        }
        cout << endl;
    }
    void wind()
    {
        int j = 5;
        for (int i = 0; i < 5; i++, j++)
        {
            stringArray[i] = inputArray[j];
        }
        cout << "Displaying the contents of the array initialized.." << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << stringArray[i];
            if(i < 4){cout<< ", ";}//only for the first 4 items
        }
        cout << endl;
    }
    void perc()
    {
        int j = 10;
        for (int i = 0; i < 5; i++, j++)
        {
            stringArray[i] = inputArray[j];
        }
        cout << "Displaying the contents of the array initialized.." << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << stringArray[i];
            if(i < 4){cout<< ", ";}//only for the first 4 items
        }
        cout << endl;
    }
};

class TypeIns : public Musicians//derived class
{
private:
    char choice;
public:
    void get()
    {
        cout<<"Type of instruments to be displayed"<<endl
            <<"a.  String instruments"<<endl
            <<"b.  Wind instruments"<<endl
            <<"c.  Percussion instruments"<<endl;
        cout<<"Enter your choice (a, b or c): ";
        cin>>choice;
    }

    void show()
    {
        int index;
        choice = (choice < 97)?(choice + 32):choice;//lowercase conversion
        switch(choice)
        {
            case 'a':
            {
                string();//calling methods from base class
                break;
            }
            case 'b':
            {
                wind();
                break;
            }
            case 'c':
            {
                perc();
                break;
            }
            default:
            {
                cout<<"Invalid choice.."<<endl;
                get();
            }
        }
    }
};

int main()
{
    TypeIns t;
    t.get();
    t.show();
    return 0;
}