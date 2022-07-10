/*Write a base class that asks the user to enter a complex number
and make a derived class that adds the complex number of its own with
the base. Finally, make a third class that is a friend of derived and
calculate the difference of the base complex number and its own complex number.*/
#include <iostream>
using namespace std;

class FriendClass;
class Complex
{
private:
    float real, imaginary;

public:
    Complex();
    Complex(float r, float i);
    float returnReal() { return real; }
    float returnImaginary() { return imaginary; }
    void display();
};
class ComplexDerived : public Complex
{
private:
    float real, imaginary;

public:
    ComplexDerived();
    ComplexDerived(float r, float i);
    Complex sumOfComplexNumbers();
    void display();
    friend class FriendClass;
};
class FriendClass
{
public:
    Complex differenceOfComplexNumbers(ComplexDerived C2);
};

Complex::Complex()
{
    cout << "Enter the complex number(in base class Complex).." << endl
         << "Real part: ";
    cin >> real;
    cout << "Imaginary part: ";
    cin >> imaginary;
}

Complex::Complex(float r, float i)
{
    real = r;
    imaginary = i;
}

ComplexDerived::ComplexDerived()
{
    cout << "Enter the complex number(in derived class ComplexDerived).." << endl
         << "Real part: ";
    cin >> real;
    cout << "Imaginary part: ";
    cin >> imaginary;
}

ComplexDerived::ComplexDerived(float r, float i)
{
    real = r;
    imaginary = i;
}

Complex ComplexDerived::sumOfComplexNumbers()
{
    return Complex(this->real + Complex::returnReal(), this->imaginary + Complex::returnImaginary());
}

Complex FriendClass::differenceOfComplexNumbers(ComplexDerived C2)
{
    return Complex(C2.Complex::returnReal() - C2.real,C2.Complex::returnImaginary() -  C2.imaginary);
    // friend class of ComplexDerived, so can access its private members, real and imaginary
    // can use public methods of class Complex because ComplexDerived inherits the class Complex
}

//using this pointers in display functions so that it can work for nameless objects.
void Complex::display()
{
    cout << this->real << " + " << this->imaginary << "i" << endl;
}

void ComplexDerived::display()
{
    cout << this->real << " + " << this->imaginary << "i" << endl;
}

int main()
{
    ComplexDerived c1;//when derived class is declared constructor of base is called first 
    //then derived class's constructor is called.
    FriendClass f1;
    cout<<"Complex number in base class: ";
    c1.Complex::display();
    cout<<"Complex number in derived class: ";
    c1.display();
    cout<<"Sum of complex numbers in base and derived classes(Calculated from derived class): ";
    c1.sumOfComplexNumbers().display();
    cout<<"Difference of complex numbers in base and derived classes(Calculated from friend class of derived class): ";
    f1.differenceOfComplexNumbers(c1).display();
    return 0;
}