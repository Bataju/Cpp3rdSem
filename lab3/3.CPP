/*Create a class called carpark that has int data member for car id, 
int data member for charge/hour, and float data member for the parked time.
Make functions to set data members and show the charges and parked hours of the
corresponding car id. Make functions for setting and showing the data members. 
Member function should be called from other functions.*/

#include<iostream>
#include<iomanip>

using namespace std;

class carpark
{
    private:
        int carId;
        int chargePerHour;
        float parkedTime;
    public:
        void setData()
        {
            cout<<"Enter the car id: ";
            cin>>carId;
            cout<<"Enter the charge per hour: ";
            cin>>chargePerHour;
            cout<<"Enter the parked time in hours: ";
            cin>>parkedTime;
        }

        void setData(int cid, int cph, float pt)
        {
            carId = cid;
            chargePerHour = cph;
            parkedTime = pt;
        }

        float returnCharge()
        {
            return chargePerHour * parkedTime;
        }

        void display()
        {
            cout<<endl<<"Car ID: "<<carId<<endl
                      <<"Charge per hour: "<<chargePerHour<<endl
                      <<"Parked hours: "<<parkedTime<<endl
                      <<"Total charge: "<<returnCharge()<<endl;
        }
};

int main()
{
    carpark c1, c2;
    c1.setData();
    c2.setData(2564, 50, 2.5);
    c1.display();
    c2.display();
    return 0;
}