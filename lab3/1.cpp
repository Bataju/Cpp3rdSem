#include<iostream>

using namespace std;

class Celcius
{
    private:
        float celcius;
    public:
        void setData(float c)
        {
            celcius = c;
        }
        float toFahrenheit()
        {
            return (32 + ((9/5) * celcius));
        }
};

class Fahrenheit
{
    private:
        float fahren;
    public:
        void setData(float f)
        {
            fahren = f;
        }
        float toCelcius()
        {
            return ((fahren-32) * 5 / 9);
        }
};

int main()
{
    Celcius c1;
    Fahrenheit f1;
    float cel, fah;
    cout<<"Enter the temperature in celcius: ";
    cin>>cel;
    c1.setData(cel);
    cout<<"Enter the temperature in fahrenheit: ";
    cin>>fah;
    f1.setData(fah);
    cout<<cel<<" degree Celcius is "<<c1.toFahrenheit()<<" degree fahrenheit."<<endl;
    cout<<fah<<" degree Fahrenheit is "<<f1.toCelcius()<<" degree celcius."<<endl;
    return 0;
}