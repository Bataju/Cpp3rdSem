/*Write a program to create a class shape with functions 
to find the area of the shapes and display the names of the shapes 
and other essential components of the class. Create derived classes 
circle, rectangle, and trapezoid each having overriding functions area() 
and display(). Write a suitable program to illustrate virtual functions 
and virtual des*/

#include<iostream>
using namespace std;
const float PI = 22/7;

class Shape //abstract class i.e. object can't be created only pointer to object
{
public:
    Shape()
    {
        cout<<"Constructor of Shape invoked.."<<endl;
    }
    virtual float area() = 0;//pure virtual function
    virtual void display() = 0;
    virtual ~Shape() //if base class's destructor is not virtual, on using delete with base class pointer only base class's destructor will be called.
    {
        cout<<"Destructor of Shape invoked.."<<endl;
    }
};

class Circle:public Shape
{
private:
    float radius;
public:
    Circle(float r=0):radius(r)
    {
        cout<<"Constructor of Circle invoked.."<<endl;
    }
    float area()
    {
        return PI * radius * radius;
    }
    void display()
    {
        cout<<"Circle"<<endl;
    }
    ~Circle()
    {
        cout<<"Destructor of Circle invoked.."<<endl;
    }
};

class Rectangle:public Shape
{
private:
    float length, breadth;
public:
    Rectangle(float l=0, float b=0):length(l), breadth(b)
    {
        cout<<"Constructor of Rectangle invoked.."<<endl;
    }
    float area()
    {
        return length * breadth;
    }
    void display()
    {
        cout<<"Rectangle"<<endl;
    }
    ~Rectangle()
    {
        cout<<"Destructor of Rectangle invoked.."<<endl;
    }
};

class Trapezoid:public Shape
{
private:
    float base1, base2, height;
public:
    Trapezoid(float b1=0, float b2=0, float h=0):base1(b1), base2(b2), height(h)
    {
        cout<<"Constructor of Trapezoid invoked.."<<endl;
    }
    float area()
    {
        return 0.5 * height * (base1 + base2);
    }
    void display()
    {
        cout<<"Trapezoid"<<endl;
    }
    ~Trapezoid()
    {
        cout<<"Destructor of Trapezoid invoked.."<<endl;
    }
};

int main()
{
    //Shape shape1; //error Shape is an abstract class so can't create object
    Shape *shapeptr[3];
    shapeptr[0] = new Circle(5);
    shapeptr[1] = new Rectangle(3, 6);
    shapeptr[2] = new Trapezoid(3, 5, 4);
    shapeptr[0]->display();
    cout<<"Area : "<<shapeptr[0]->area()<<endl;
    shapeptr[1]->display();
    cout<<"Area : "<<shapeptr[1]->area()<<endl;
    shapeptr[2]->display();
    cout<<"Area : "<<shapeptr[2]->area()<<endl;
    delete shapeptr[0];
    delete shapeptr[1];
    delete shapeptr[2];
    return 0; 
}