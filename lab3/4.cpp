/*Write a program with classes to represent a circle, rectangle, and triangle.
Each class should have data members to represent the actual objects and member functions to read and display objects,
find perimeter and area of the objects, and other useful functions. Use the classes to create objects in your program.*/

#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14;

class Circle
{
private:
    float radius;

public:
    void setData()
    {
        cout << "Enter the radius of circle: ";
        cin >> radius;
    }

    float calculateArea()
    {
        return PI * radius * radius;
    }

    float calculatePerimeter()
    {
        return 2 * PI * radius;
    }

    void showData()
    {
        cout << endl
             << "RADIUS OF CIRCLE: " << radius << endl;
    }
};

class Rectangle
{
private:
    float length;
    float breadth;

public:
    void setData()
    {
        cout << "Enter the length of rectangle: ";
        cin >> length;
        cout << "Enter the breadth of reactangle: ";
        cin >> breadth;
    }

    float calculateArea()
    {
        return length * breadth;
    }

    float calculatePerimeter()
    {
        return 2 * (length + breadth);
    }

    void showData()
    {
        cout << endl
             << "LENGTH OF RECTANGLE: " << length << endl
             << "BREADTH OF RECTANGLE: " << breadth << endl;
    }
};

class Triangle
{
private:
    float sideA;
    float sideB;
    float sideC;

public:
    void setData()
    {
        cout << "Enter the side a of triangle: ";
        cin >> sideA;
        cout << "Enter the side b of triangle: ";
        cin >> sideB;
        cout << "Enter the side c of triangle: ";
        cin >> sideC;
    }

    float calculateArea()
    {
        float s;
        s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    float calculatePerimeter()
    {
        return sideA + sideB + sideC;
    }

    void showData()
    {
        cout << endl
             << "SIDE a OF TRIANGLE: " << sideA << endl
             << "SIDE b OF TRIANGLE: " << sideB << endl
             << "SIDE c OF TRIANGLE: " << sideC << endl;
    }
};

int main()
{
    Circle c1;
    Rectangle r1;
    Triangle t1;
    c1.setData();
    r1.setData();
    t1.setData();
    c1.showData();
    cout << "AREA OF CIRCLE: " << c1.calculateArea() << endl
         << "PERIMETER OF CIRCLE: " << c1.calculatePerimeter() << endl;
    r1.showData();
    cout << "AREA OF RECTANGLE: " << r1.calculateArea() << endl
         << "PERIMETER OF RECTANGLE: " << r1.calculatePerimeter() << endl;
    t1.showData();
    cout << "AREA OF TRIANGLE: " << t1.calculateArea() << endl
         << "PERIMETER OF TRIANGLE: " << t1.calculatePerimeter() << endl;
    return 0;
}