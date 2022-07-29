#include <iostream>
using namespace std;

class Meter;
class Feet;

class Meter
{
private:
    float meters;

public:
    Meter(float m = 0) : meters(m){}
    Meter(Feet); 
    float returnMeters()
    {
        return meters;
    }
    void display()
    {
        cout << this->meters << " meters..." << endl;
    }
};

class Feet
{
private:
    float feet;

public:
    Feet(float f = 0) : feet(f){}
    Feet(Meter);
    float returnFeet()
    {
        return feet;
    }
    void display()
    {
        cout << this->feet << " feet..." << endl;
    }
};

Meter::Meter(Feet f) // imperial to metric
{
    this->meters = f.returnFeet() * 0.3; //1ft = 0.3 metres
}

Feet::Feet(Meter m) // metric to imperial
{
   this->feet = m.returnMeters() / 0.3;
}

int main()
{
    Feet fobj1(5.5), fobj2;
    Meter mobj1, mobj2(1.71);

    cout << "Distance 1..." << endl;
    mobj1 = fobj1;
    mobj1.display();
    fobj1.display();

    cout << "Distance 2..." << endl;
    fobj2=mobj2;//conversion from metric to imperial
    mobj2.display();
    fobj2.display();
    return 0;
}