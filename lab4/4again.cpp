/*Assume that one constructor initializes data member say num_vehicle, hour, and rate.
There should be a 10% discount if num_vehicle exceeds 10.
Display the total charge. Use two objects and show a bit-by-bit copy of one object
to another (make your own copy constructor).*/

#include <iostream>
using namespace std;

class Parking
{
private:
    int numOfVehicle;
    float hour;
    float rate;

public:
    Parking(int noOfVehicle = 0, float hr = 0, float rt = 0)
    {
        cout << "Constructor invoked..." << endl;
        numOfVehicle = noOfVehicle;
        hour = hr;
        rate = rt;
    }
    Parking(Parking &p);
    void getRateAfterDiscount();
    void showData();
    void displayTotalCost();
    ~Parking();
};

Parking::Parking(Parking &p)
{
    numOfVehicle = p.numOfVehicle;
    hour = p.hour;
    rate = p.rate;
    cout<<"Copy constructor called..."<<endl;
}

Parking::~Parking()
{
    cout << "Destructor invoked..." << endl;
}

void Parking::getRateAfterDiscount()
{
    if (numOfVehicle > 10)
        rate = 0.9 * rate; // 10 percent discount
}

void Parking::showData()
{
    cout << endl
         << "Number of vehicles: " << numOfVehicle << endl
         << "Parked time (in hours): " << hour << endl
         << "Rate: " << rate << endl;
}

void Parking::displayTotalCost()
{
    getRateAfterDiscount(); // alter rate if number of vehicles exceeds 10
    cout << "Total cost after calculating discount: Rs. " << numOfVehicle * hour * rate << endl
         << endl;
}

int main()
{
    Parking p1(5, 2.5, 25);
    Parking p2 = p1;
    Parking p3(p1);
    p1.showData();
    p1.displayTotalCost();
    p2.showData();
    p2.displayTotalCost();
    p3.showData();
    p3.displayTotalCost();
    return 0;
}