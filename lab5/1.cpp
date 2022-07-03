/*Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions
 of another class if the former class is made friend to the latter.
Make least possible classes to demonstrate all the above in a single program without conflict.*/

#include <iostream>
using namespace std;

class CartesianCoordinates; // declaration because it's used in class Operations

class Operations
{
private:
    char operatorSymbol;
public:
    // a member function that is friend to another function
    CartesianCoordinates add(CartesianCoordinates c1, CartesianCoordinates c2);

    // declaration of friend functions
    friend CartesianCoordinates subtract(CartesianCoordinates c1, CartesianCoordinates c2);
    friend CartesianCoordinates multiply(CartesianCoordinates c1, CartesianCoordinates c2);
    friend CartesianCoordinates divide(CartesianCoordinates c1, CartesianCoordinates c2);
};

class CartesianCoordinates
{
private:
    float x;
    float y;

public:
    CartesianCoordinates(float xIn = 0, float yIn = 0)
    {
        x = xIn;
        y = yIn;
    }

    void showData()
    {
        cout << "(" << x << " , " << y << ")" << endl;
    }

    // declaration of a member function of another class as friend.
    friend CartesianCoordinates Operations::add(CartesianCoordinates c1, CartesianCoordinates c2);

    // declaration of friend functions
    friend CartesianCoordinates subtract(CartesianCoordinates c1, CartesianCoordinates c2);
    friend CartesianCoordinates multiply(CartesianCoordinates c1, CartesianCoordinates c2);
    friend CartesianCoordinates divide(CartesianCoordinates c1, CartesianCoordinates c2);
};

// function definition of member function of class Operations
// and friend function of class CartesianCoordinates
CartesianCoordinates Operations::add(CartesianCoordinates c1, CartesianCoordinates c2)
{
    return CartesianCoordinates(c1.x + c2.x, c1.y + c2.y); // returning nameless object
}

// friend functions of both the classes
CartesianCoordinates subtract(CartesianCoordinates c1, CartesianCoordinates c2)
{
    return CartesianCoordinates(c1.x - c2.x, c1.y - c2.y);
}
CartesianCoordinates multiply(CartesianCoordinates c1, CartesianCoordinates c2)
{
    return CartesianCoordinates(c1.x * c2.x, c1.y * c2.y);
}
CartesianCoordinates divide(CartesianCoordinates c1, CartesianCoordinates c2)
{
    return CartesianCoordinates(c1.x / c2.x, c1.y / c2.y);
}

int main()
{
    CartesianCoordinates c1(8.5, 7), c2(1, 5), c3;
    Operations operation;
    cout<<"Addition.."<<endl;
    c3 = operation.add(c1, c2);
    c3.showData();
    cout<<"Subtraction.."<<endl;
    c3 = subtract(c1, c2);
    c3.showData();
    cout<<"Multiplication.."<<endl;
    c3 = multiply(c1, c2);
    c3.showData();
    cout<<"Division.."<<endl;
    c3 = divide(c1, c2);
    c3.showData();
    return 0;
}