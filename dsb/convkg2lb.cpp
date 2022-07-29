#include<iostream>
using namespace std;

class Pound;

class Kg
{
private:
    float kgs;
public:
    Kg(float kg=0):kgs(kg){}
    Kg(Pound p);
    void display();
    float returnKgs();
};

class Pound
{
private:
    float lbs;
public:
    Pound(float lb=0):lbs(lb){}
    Pound(Kg k);
    void display();
    float returnLbs();
};

float Kg::returnKgs()
{
    return this->kgs;
}

void Kg::display()
{
    cout<<this->kgs<<" kgs..."<<endl;
}

float Pound::returnLbs()
{
    return this->lbs;
}

void Pound::display()
{
    cout<<this->lbs<<" pounds.."<<endl;
}

Kg::Kg(Pound p)
{
    this->kgs = p.returnLbs() / 2.2;  //1kg = 2.2 lb
}

Pound::Pound(Kg k)
{
    this->lbs = k.returnKgs() * 2.2;
}

int main()
{
    Kg kgObj1(55.657), kgObj2;
    Pound  poundObj1, poundObj2(121.254);
    poundObj1 = kgObj1;
    cout<<"Mass 1"<<endl;
    kgObj1.display();
    poundObj1.display();

    kgObj2 = poundObj2;
    cout<<"Mass 2"<<endl;
    kgObj2.display();
    poundObj2.display();
    return 0;
}