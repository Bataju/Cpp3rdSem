#include<iostream>
using namespace std;

class Galon;

class Litre
{
private:
    int litres;
    float millilitres;
public:
    Litre(int l=0, float m=0):litres(l), millilitres(m){}
    Litre(Galon);
    int returnLitres(){return this->litres;}
    float returnMillilitres(){return this->millilitres;}
    void display()
    {
        cout<<this->litres<<" litres and "<<this->millilitres<<" millilitres."<<endl;
    }
};

class Galon
{
private:
    int galons;
    float milligalons;
public:
    Galon(int g=0, float m=0):galons(g), milligalons(m){}
    Galon(Litre);
    int returnGalons(){return this->galons;}
    int returnMilligalons(){return this->milligalons;}
    void display()
    {
        cout<<this->galons<<" galons and "<<this->milligalons<<" milligalons."<<endl;
    }
};

//1 galon = 3.785411784 liters
Litre::Litre(Galon g)
{
    float totalMilligalons = g.returnGalons() * 1000 + g.returnMilligalons();
    float totalMillilitres = totalMilligalons * 3.785411784;
    this->litres = static_cast<int>(totalMillilitres / 1000);
    this->millilitres = totalMillilitres - this->litres * 1000;
}

Galon::Galon(Litre l)
{
    float totalMillilitres = l.returnLitres() *1000 + l.returnMillilitres();
    float totalMilligalons = totalMillilitres / 3.785411784;
    this->galons = static_cast<int>(totalMilligalons / 1000);
    this->milligalons = totalMilligalons - this->galons * 1000;
}

int main()
{
    Litre lobj1(5, 250), lobj2;
    Galon gobj1, gobj2(5, 2.5);

    cout<<"Volume 1.."<<endl;
    gobj1 = lobj1;
    lobj1.display();
    gobj1.display();

    cout<<"Volume 2.."<<endl;
    lobj2 = gobj2;
    lobj2.display();
    gobj2.display();
    return 0;
}