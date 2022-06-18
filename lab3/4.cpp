/*Write a program with classes to represent a circle, rectangle, and triangle. 
Each class should have data members to represent the actual objects and member functions 
to read and display objects, find perimeter and area of the objects, and other useful functions.
Use the classes to create objects in your program.*/

#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.14;

class Circle
{
    private:
        float radius;
    public:
        void setData()
        {
            cout<<"CIRCLE"<<endl;
            cout<<"Enter radius of circle: ";
            cin>>radius;
        }

        void setData(float rad)
        {
            radius = rad;
        }

        float returnArea()
        {
            return PI*radius*radius;
        }

        float returnPerimeter()
        {
            return 2*PI*radius;
        }

        void display()
        {
            cout<<"A circle of radius = "<<radius<<". Area = "<<returnArea()<<" and Perimeter = "<<returnPerimeter()<<"."<<endl;
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
            cout<<"RECTANGLE"<<endl;
            cout<<"Enter length of rectangle: ";
            cin>>length;
            cout<<"Enter breadth of rectangle: ";
            cin>>breadth;
        }

        void setData(float len, float bre)
        {
            length = len;
            breadth = bre;
        }

        float returnArea()
        {
            return length * breadth;
        }

        float returnPerimeter()
        {
            return 2*(length+breadth);
        }

        void display()
        {
            cout<<"A rectangle of length = "<<length<<" and breadth = "<<breadth<<". Area = "<<returnArea()<<" and Perimeter = "<<returnPerimeter()<<"."<<endl;
        }
};

class Triangle
{
    private:
        float a;
        float b;
        float c;
    public:
        void setData()
        {
            cout<<"TRIANGLE"<<endl;
            cout<<"Enter side a of triangle: ";
            cin>>a;
            cout<<"Enter side b of triangle: ";
            cin>>b;
            cout<<"Enter side c of triangle: ";
            cin>>c;
            if((a+b) <= c || (b+c) <= a || (a+c) <= b)
            {
                cout<<"Invalid input for sides of triangle. "<<endl;
                setData();
            }
        }

        void setData(float a, float b, float c)
        {
            a = a;
            b = b;
            c = c;
        }

        float returnArea()
        {
            float s = (a+b+c)/2;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }

        float returnPerimeter()
        {
            return a+b+c;
        }

        void display()
        {
            cout<<"A triangle with sides: a = "<<a<<" , b = "<<b<<" and c = "<<c<<". Area = "<<returnArea()<<" and Perimeter = "<<returnPerimeter()<<"."<<endl;
        }
};

int main()
{
    Circle c; Rectangle r; Triangle t;
    c.setData();
    r.setData();
    t.setData();
    c.display();
    r.display();
    t.display();
    return 0;
}