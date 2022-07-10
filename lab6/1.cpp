/*Write a program that can convert the Distance (meter, centimeter) to meters measurement
 in float and vice versa. Make a class distance with two data members, meter and centimeter.
 You can add function members as per your requirement.*/

#include <iostream>
using namespace std;

class Distance
{
private:
    int meter;
    int centimeter;
public:
    Distance(int m ,int c):meter(m), centimeter(c){}
    Distance(float m)//basic(Float) to userdefined data type Distance
    {
        this->meter = static_cast<int>(m);
        this->centimeter = 100 * (m - (this->meter));
    }
    operator float()//userdefined to basic data type float
    {
        return(this->meter + static_cast<float>(this->centimeter) / 100);
    }
    void display()
    {
        cout<<this->meter<<" meters and "<<this->centimeter<<" centimeters."<<endl;
    }
};

int main()
{
    Distance d1(5, 10);
    Distance d2 = 6.9; //basic to userdefined
    d1.display();
    d2.display();

    float f1 = d2;//userdefined to basic
    cout<<f1<<" meters."<<endl;
    return 0;
}