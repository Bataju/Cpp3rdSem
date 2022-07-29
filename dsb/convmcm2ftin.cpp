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
    MetricSystem(ImperialSystem); 
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
    ImperialSystem(MetricSystem);
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
    MetricSystem m1, m2(10, 55);

    cout << "Distance 1..." << endl;
    m1 = i1;//conversion from imperial to metric
    i1.displayImperialSystem();
    m1.displayMetricSystem();

    cout << "Distance 2..." << endl;
    i2 = m2;//conversion from metric to imperial
    i2.displayImperialSystem();
    m2.displayMetricSystem();
    return 0;
}