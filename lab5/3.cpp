/*Write a program to compare two objects of a class that contains an integer value
as its data member. Make overloading functions to overload equality(==), less than(<),
greater than(>), not equal (!=), greater than or equal to (>=), and less than or equal
to(<=) operators using member operator functions.*/

#include <iostream>
using namespace std;

class Number
{
private:
    int number;

public:
    Number(int num = 0) : number(num) {}
    // single paramter operator overloading i.e. using member functions
    int operator==(Number n2);
    int operator<(Number n2);
    int operator>(Number n2);
    int operator!=(Number n2);
    int operator>=(Number n2);
    int operator<=(Number n2);
};

int Number::operator==(Number n2)
{
    return (number == n2.number);
}

int Number::operator<(Number n2)
{
    return (number < n2.number);
}

int Number::operator>(Number n2)
{
    return (number > n2.number);
}

int Number::operator!=(Number n2)
{
    return (number != n2.number);
}

int Number::operator>=(Number n2)
{
    return (number >= n2.number);
}

int Number::operator<=(Number n2)
{
    return (number <= n2.number);
}

int main()
{
    Number n1(8);
    Number n2(45);
    cout << "Is object 1 == object 2? " << (n1 == n2) << endl
         << "Is object 1 < object 2? " << (n1 < n2) << endl
         << "Is object 1 > object 2? " << (n1 > n2) << endl
         << "Is object 1 != object 2? " << (n1 != n2) << endl
         << "Is object 1 >= object 2? " << (n1 >= n2) << endl
         << "Is object 1 <= object 2? " << (n1 <= n2) << endl;
    return 0;
}