/*Write a program to create a user-defined manipulator that will format 
the output by setting the width, precision, and fill character at the 
same time by passing arguments.*/

#include<iostream>
using namespace std;

class MyManip
{
    private:
        int width;
        int precision;
        char fillCharacter;
    public:
        MyManip(int w=0, int p=0, char c='0'):width(w), precision(p), fillCharacter(c){}
        friend ostream& operator << (ostream & os, MyManip m);    
};

ostream& operator<< (ostream& os, MyManip m) //<< overloaded as a binary operator between os and m
{
    os.width(m.width); //eqv to cout.width(m.width)
    os.precision(m.precision);
    os.fill(m.fillCharacter);
    return os; //eqv to return cout in case of cascading
}

int main()
{
    MyManip m1(8, 6, '0');
    cout<<m1<<45.263<<endl;
    cout<<MyManip(10, 7, '#')<<45.263<<endl;
    return 0;
}