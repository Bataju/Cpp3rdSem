/*Write two classes to store distances in meter-centimeter and feet-inch systems respectively.
Write conversions functions so that the program can convert objects of both types.*/

#include <iostream>
using namespace std;

class MetricSystem;
class ImperialSystem;

class MetricSystem
{
private:
    float meters;
    float centimeters;

public:
    MetricSystem(float m = 0, float c = 0) : meters(m), centimeters(c) {}
    MetricSystem(ImperialSystem); // imperial to metric
    float returnMeters()
    {
        return meters;
    }
    float returnCentimeters()
    {
        return centimeters;
    }
    void displayMetricSystem()
    {
        cout << this->meters << " meters and " << this->centimeters << " centimeters." << endl;
    }
};

class ImperialSystem
{
private:
    float feet;
    float inches;

public:
    ImperialSystem(float f = 0, float i = 0) : feet(f), inches(i) {}
    ImperialSystem(MetricSystem); // metric to imperial
    float returnFeet()
    {
        return feet;
    }
    float returnInches()
    {
        return inches;
    }
    void displayImperialSystem()
    {
        cout << this->feet << " feet and " << this->inches << " inches." << endl;
    }
};

MetricSystem::MetricSystem(ImperialSystem imp) // imperial to metric
{
    float totalInches = imp.returnFeet() * 12 + imp.returnInches();
    float totalCentimeters = totalInches * 2.54; // 1 inch = 2.54 cms
    this->meters = static_cast<int>(totalCentimeters / 100);
    this->centimeters = totalCentimeters - (this->meters) * 100;
}

ImperialSystem::ImperialSystem(MetricSystem m) // metric to imperial
{
    float totalCentimeters = m.returnMeters() * 100 + m.returnCentimeters();
    float totalInches = totalCentimeters / 2.54;
    this->feet = static_cast<int>(totalInches / 12);
    this->inches = totalInches - (this->feet) * 12;
}

int main()
{
    ImperialSystem i1(5, 5), i2;
    MetricSystem m1(10, 55), m2;

    cout << "Distance 1..." << endl;
    i1.displayImperialSystem();
    m2 = i1;//conversion from imperial to metric
    m2.displayMetricSystem();

    cout << "Distance 2..." << endl;
    i2 = m1;//conversion from metric to imperial
    i2.displayImperialSystem();
    m1.displayMetricSystem();
    return 0;
}