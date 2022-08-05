/*Create a polymorphic class Vehicle and create other derived classes 
Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast 
and typeid operators in this program.*/

#include<iostream>
#include<typeinfo>
#include"demangle.hpp"
using namespace std;

class Vehicle
{
public:
    virtual void displayType()
    {
        cout<<"Vehicle.."<<endl;
    }
};

class Bus:public Vehicle
{
public:
    void displayType()
    {
        cout<<"Bus.."<<endl;
    }
};

class Car:public Vehicle
{
public:
    void displayType()
    {
        cout<<"Car.."<<endl;
    }
};

class Bike:public Vehicle
{
public:
    void displayType()
    {
        cout<<"Bike.."<<endl;
    }
};

int main()
{
    Vehicle *vhptr1, *vhptr2, *vhptr3;
    Bus *busptr = new Bus;
    Car *carptr = new Car;
    Bike *bikeptr = new Bike;

    vhptr1 = dynamic_cast<Vehicle*>(busptr);
    vhptr2 = dynamic_cast<Vehicle*>(carptr);
    vhptr3 = dynamic_cast<Vehicle*>(bikeptr);

    cout<<endl<<"Type of *vhptr1 after upcasting: "<<demangle(typeid(*vhptr1).name())<<endl;
    cout<<"Type of *vhptr2 after upcasting: "<<demangle(typeid(*vhptr2).name())<<endl;
    cout<<"Type of *vhptr3 after upcasting: "<<demangle(typeid(*vhptr3).name())<<endl;

    cout<<endl<<"From vhptr1"<<endl;
    vhptr1->displayType();
    cout<<endl<<"From vhptr2"<<endl;
    vhptr2->displayType();
    cout<<endl<<"From vhptr3"<<endl;
    vhptr3->displayType();

    //incorrect downcasting
    busptr = dynamic_cast<Bus*>(vhptr2);
    if(busptr != NULL)
        cout<<endl<<"Cast vhptr2 to Bus* success.."<<endl;
    else
    {
        cout<<endl<<"Cast vhptr2 to Bus* failed.."<<endl;
        cout<<"Reason: The type of *vhptr2 is currently "<<demangle(typeid(*vhptr2).name())<<endl;
    }   
    // carptr = dynamic_cast<Car*>(vhptr3);
    // if(carptr != NULL)
    //     cout<<"Cast vhptr3 to Car* success.."<<endl;
    // else
    // {
    //     cout<<"Cast vhptr3 to Car* failed.."<<endl;
    //     cout<<"Reason: The type of *vhptr3 is currently "<<demangle(typeid(*vhptr3).name())<<endl;
    // }
    // bikeptr = dynamic_cast<Bike*>(vhptr1);
    // if(carptr != NULL)
    //     cout<<"Cast vhptr1 to Bike* success.."<<endl;
    // else
    // {
    //     cout<<"Cast vhptr1 to Bike* failed.."<<endl;
    //     cout<<"Reason: The type of *vhptr1 is currently "<<demangle(typeid(*vhptr1).name())<<endl;
    // }

    //correct downcasting
    busptr = dynamic_cast<Bus*>(vhptr1);
    if(busptr != NULL)
        cout<<endl<<"Cast vhptr1 to Bus* success.."<<endl;
    else
        cout<<endl<<"Cast vhptr1 to Bus* failed.."<<endl;

    // carptr = dynamic_cast<Car*>(vhptr2);
    // if(carptr != NULL)
    //     cout<<"Cast vhptr2 to Car* success.."<<endl;
    // else
    //     cout<<"Cast vhptr2 to Car* failed.."<<endl;

    // bikeptr = dynamic_cast<Bike*>(vhptr3);
    // if(carptr != NULL)
    //     cout<<"Cast vhptr3 to Bike* success.."<<endl;
    // else
    //     cout<<"Cast vhptr3 to Bike* failed.."<<endl;

    delete busptr;
    delete carptr;
    delete bikeptr;
    return 0;
}

    //base class pointer can easily point to derived class object
    //vhptr1 = busptr; is valid
    //vhptr1->displayNumberOfWheels(); works fine
    //this is upcasting and can also be performed explicitly like
    //vhptr1 = (Vehicle*)busptr; or vhptr1 = dynamic_cast<Vehicle*>(busptr);

    //downcasting to incorrect type
    //carptr = (Car*)vhptr1; this works but is incorrect semantically
    //because vhptr1 was originally upcasted from busptr not carptr

