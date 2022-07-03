/*Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions
 of another class if the former class is made friend to the latter.
Make least possible classes to demonstrate all the above in a single program without conflict.*/

#include <iostream>
using namespace std;

class Coordinate1;
class Coordinate2;
// Coordinate2 add(Coordinate1 &c1, Coordinate2 &c2); declaration

class Coordinate1
{
private:
    float x;
    float y;

public:
    Coordinate1(float xIn = 0, float yIn = 0) : x(xIn), y(yIn) {} // constructor - member initializer list

    // declaration of friend function that is member function of another class
    friend Coordinate2 Coordinate2::add(Coordinate1 &c1, Coordinate2 &c2); //add function is not yet declared

    // friend functions to both the classses
    friend Coordinate1 subtract(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 multiply(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 divide(Coordinate1 &c1, Coordinate2 &c2);
};

class Coordinate2
{
private:
    float x;
    float y;

public:
    Coordinate2(float xIn = 0, float yIn = 0) : x(xIn), y(yIn) {} // constructor - member insitializer list
    // declaration of member function that is friend to another class
    Coordinate2 add(Coordinate1 &c1, Coordinate2 &c2);

    // friend functions to both the classes
    friend Coordinate1 subtract(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 multiply(Coordinate1 &c1, Coordinate2 &c2);
    friend Coordinate1 divide(Coordinate1 &c1, Coordinate2 &c2);
};

// function definitions
Coordinate2 Coordinate2::add(Coordinate1 &c1, Coordinate2 &c2)
{
    return Coordinate2(c1.x + c2.x, c1.y + c2.y); //whyyyyyyyy (Coordinate2 is already friend to Coordinate1)
    //maybe because add function was not declared when it was declared friend to another class
}

int main()
{
    return 0;
}