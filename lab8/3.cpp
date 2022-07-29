/*Write a program to overload stream operators to read a complex number
and display the complex number in a+ib format.*/

#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imaginary;

public:
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}
    void getComplex()
    {
        cout << "Real part: ";
        cin >> this->real;
        cout << "Imaginary part: ";
        cin >> this->imaginary;
    }
    void displayComplex()
    {
        cout << real << "+" << imaginary << "i" << endl;
    }
    friend ostream &operator<<(ostream &os, Complex &c);
    friend istream &operator>>(istream &is, Complex &c);
};

ostream &operator<<(ostream &os, Complex &c) // reference must be passed or else c becomes local variable
{
    c.displayComplex();
    return os;
}

istream &operator>>(istream &is, Complex &c)
{
    c.getComplex();
    return is;
}

int main()
{
    Complex c1, c2(5, 2);
    cout << c2;
    cout << "Enter a complex number.." << endl;
    cin >> c1;
    cout << c1;
    return 0;
}