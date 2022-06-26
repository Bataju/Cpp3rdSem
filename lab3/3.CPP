/*Create a class called carpark that has int data member for car id,
int data member for charge/hour, and float data member for the parked time.
Make functions to set data members and show the charges and parked hours of the corresponding car id.
 Make functions for setting and showing the data members. Member function should be called from other functions.*/

#include <iostream>
using namespace std;

class Carpark
{
private:
    int carId;
    int chargePerHour;
    float parkedTime;

public:
    void setData()
    {
        cout << "Enter the car ID: ";
        cin >> carId;
        cout << "Enter the charge per hour: ";
        cin >> chargePerHour;
        cout << "Enter the parked time: ";
        cin >> parkedTime;
    }

    float calculateTotalCharge()
    {
        return chargePerHour * parkedTime;
    }

    void showData()
    {
        cout << "Car ID: " << carId << endl
             << "Charge per hour: " << chargePerHour << endl
             << "Parked time: " << parkedTime << endl;
    }
};

int main()
{
    Carpark c1;
    c1.setData();
    c1.showData();
    cout << "Total charge: " << c1.calculateTotalCharge() << endl;
    return 0;
}