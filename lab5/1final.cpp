/*Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions
of another class if the former class is made friend to the latter.
Make least possible classes to demonstrate all the above in a single program without conflict.*/

#include <iostream>
using namespace std;

class Coordinate2;
class FriendClass;

class Coordinate1
{
private:
    float x;
    float y;

public:
    Coordinate1(float xIn = 0, float yIn = 0) : x(xIn), y(yIn) {} // constructor - member initializer list

    void displayCoordinates()
    {
        cout << "(" << x << " , " << y << ")" << endl;
    }

    // declaration of member function that is friend function of another class
    Coordinate1 add(Coordinate1 &c1, Coordinate2 &c2); //reference

    // friend functions to both the classses
    friend Coordinate1 subtract(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 multiply(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 divide(Coordinate1 &c1, Coordinate2 &c2);

    friend class FriendClass;
};

class Coordinate2
{
private:
    float x;
    float y;

public:
    Coordinate2(float xIn = 0, float yIn = 0) : x(xIn), y(yIn) {} // constructor - member insitializer list

    // declaration of friend function that is member function of another class
    friend Coordinate1 Coordinate1::add(Coordinate1 &c1, Coordinate2 &c2);

    // friend functions to both the classes
    friend Coordinate1 subtract(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 multiply(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 divide(Coordinate1 &c1, Coordinate2 &c2);
};

// this class is friend class of Coordinate1 so all its members will be able to access the private members of Coordinate1
class FriendClass
{
public:
    void displayCoordinate1(Coordinate1 &c1) // this is a member function of FriendClass(which is friend class of Coordinate1)
    {                                        // therefore is friend function(i.e can access private data members) of Coordinate1
        cout << "Displaying coordinate1 from friend class (FriendClass)... " << endl;
        cout << "(" << c1.x << " , " << c1.y << ")" << endl;
    }
};

// function definitions
Coordinate1 Coordinate1::add(Coordinate1 &c1, Coordinate2 &c2)
{
    return Coordinate1(c1.x + c2.x, c1.y + c2.y); // returning nameless object
}

Coordinate1 subtract(Coordinate1 &c1, Coordinate2 &c2)
{
    return Coordinate1(c1.x - c2.x, c1.y - c2.y);
}

Coordinate1 multiply(Coordinate1 &c1, Coordinate2 &c2)
{
    return Coordinate1(c1.x * c2.x, c1.y * c2.y);
}

Coordinate1 divide(Coordinate1 &c1, Coordinate2 &c2)
{
    return Coordinate1(c1.x / c2.x, c1.y / c2.y);
}

int main()
{
    Coordinate1 A(5, 4.5);
    Coordinate2 B(2.5, 8);
    Coordinate1 C;
    FriendClass demo;
    cout << endl
         << "Demonstration of a particular member function of one class as friend function of another..." << endl;
    cout << "ADDING.." << endl;
    C = A.add(A, B);
    C.displayCoordinates();
    cout << endl
         << "Demonstration of friend functions as bridge between two classes..." << endl;
    cout << "SUBTRACTING.." << endl;
    C = subtract(A, B);
    C.displayCoordinates();
    cout << "MULTIPLYING.." << endl;
    C = multiply(A, B);
    C.displayCoordinates();
    cout << "DIVIDING.." << endl;
    C = divide(A, B);
    C.displayCoordinates();
    cout << endl
         << "Demonstration of friend class..." << endl;
    demo.displayCoordinate1(A);
    return 0;
}