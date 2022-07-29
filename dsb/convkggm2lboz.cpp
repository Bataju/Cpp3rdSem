#include<iostream>
using namespace std;

class Pound;

class Kg
{
private:
    int kgs;
    float gms;
public:
    Kg(int kg=0, float gm = 0):kgs(kg), gms(gm){}
    Kg(Pound p);
    void display();
    int returnKgs();
    float returnGms();
};

class Pound
{
private:
    int lbs;
    float ounces;
public:
    Pound(int lb=0, float oz=0):lbs(lb), ounces(oz){}
    Pound(Kg k);
    void display();
    int returnLbs();
    float returnOzs();
};

int Kg::returnKgs()
{
    return this->kgs;
}

float Kg::returnGms()
{
    return this->gms;
}

void Kg::display()
{
    cout<<this->kgs<<" kgs and "<<this->gms<<" grams..."<<endl;
}

int Pound::returnLbs()
{
    return this->lbs;
}

float Pound::returnOzs()
{
    return this->ounces;
}

void Pound::display()
{
    cout<<this->lbs<<" pounds and "<<this->ounces<<" ounces..."<<endl;
}

Kg::Kg(Pound p)
{
    float totalOunces = p.returnOzs() + p.returnLbs() * 16;
    float totalGrams = totalOunces / (16 * 2.2 / 1000); //1kg = 2.2 lb so 1gm = 16*2.2/1000 ozs
    this->kgs = static_cast<int>(totalGrams/1000);
    this->gms = totalGrams - (this->kgs * 1000);
}

Pound::Pound(Kg k)
{
    float totalGrams = k.returnKgs() *1000 + k.returnGms();
    float totalOunces = totalGrams * (16 * 2.2 / 1000);
    this->lbs = static_cast<int>(totalOunces / 16);
    this->ounces = totalOunces - (this->lbs * 16);
}

int main()
{
    Kg kgObj1(55, 25.55), kgObj2;
    Pound  poundObj1, poundObj2(121, 15.2);
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