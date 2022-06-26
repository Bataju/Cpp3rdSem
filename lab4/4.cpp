/*Assume that one constructor initializes data member say num_vehicle, hour, and rate. 
There should be a 10% discount if num_vehicle exceeds 10. 
Display the total charge. Use two objects and show a bit-by-bit copy of one object 
to another (make your own copy constructor).*/

#include<iostream>
using namespace std;

class VehicleDetails
{
    private:
        int numVehicle;
        float hour;
        float rate;
    public:
        VehicleDetails(int numVeh, float hr, float rt)
        {
            numVehicle = numVeh;
            hour = hr;
            rate = rt;
        }

        VehicleDetails(VehicleDetails &vd)//own copy constructor
        {
            numVehicle = vd.numVehicle;
            hour = vd.hour;
            rate = vd.rate;
        }

        void displayRate()
        {
            cout<<"Total cost : "<< ((numVehicle>10) ? (0.9*rate*hour) : (rate*hour))<<endl;
        }
};

int main()
{
    VehicleDetails v1(15, 3.5, 10000);
    v1.displayRate();
    VehicleDetails v2(v1);//copy constructor
    v2.displayRate();
    return 0;
}