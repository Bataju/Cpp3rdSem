#include<iostream>
#include<cmath>
using namespace std;
const float PI = 3.141592653589793238;

class Polar;

class Cartesian
{
    private:
        float x;
        float y;
    public:
        Cartesian(float xIn=0, float yIn=0):x(xIn), y(yIn){}
        Cartesian(Polar p);
        float returnX();
        float returnY();
        void display();
};

class Polar
{
    private:
        float r;
        float theta;
    public:
        Polar(float rIn=0, float thetaIn=0):r(rIn), theta(thetaIn){}
        Polar(Cartesian c);
        float returnR();
        float returnTheta();
        void display();
};

Cartesian::Cartesian(Polar p)
{
    this->x = p.returnR() * cos(p.returnTheta() * (PI / 180));//converting to radians
    this->y = p.returnR() * sin(p.returnTheta() * (PI / 180));
}

float Cartesian::returnX()
{
    return this->x;
}

float Cartesian::returnY()
{
    return this->y;
}

void Cartesian::display()
{
    cout<<"(x, y) = ("<<this->x<<", "<<this->y<<")"<<endl;
}

Polar::Polar(Cartesian c)
{
    this->r = sqrt((c.returnX()*c.returnX()) + (c.returnY() * c.returnY()));
    this->theta = atan(c.returnY() / c.returnX()) * 180 / PI; //converting to degrees
}

float Polar::returnR()
{
    return this->r;
}

float Polar::returnTheta()
{
    return this->theta;
}

void Polar::display()
{
    cout<<"(r, theta) = ("<<this->r<<", "<<this->theta<<" degrees)"<<endl;
}

int main()
{
    Cartesian cobj1(2, 5), cobj2;
    Polar pobj1, pobj2(5, 30);
    pobj1 = cobj1;
    cout<<"Coordinate 1"<<endl;
    cobj1.display();
    pobj1.display();

    cobj2 = pobj2;
    cout<<"Coordinate 2"<<endl;
    cobj2.display();
    pobj2.display();
    return 0;
}