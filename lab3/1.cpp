/*Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale
 and vice versa using the basic concept of class and object. Make separate classes for Celsius and Fahrenheit
 which will have the private members that hold the temperature value and make conversion functions in each class
 for conversion from one to another. For example, you need to have a function toFahrenheit() in class Celsius
  that converts to Fahrenheit scale and returns the value.*/

#include <iostream>
using namespace std;

class Celcius
{
private:
    float tempInCel;

public:
    void setData()
    {
        cout << "Enter temperature in celcius: ";
        cin >> tempInCel;
    }
    void setData(float temp)
    {
        tempInCel = temp;
    }
    float celciusToFahrenheit()
    {
        return tempInCel * (9 / 5) + 32;
    }
    void showData()
    {
        cout << "Temperature in celcius: " << tempInCel << endl;
    }
};

class Fahrenheit
{
private:
    float tempInFah;

public:
    void setData()
    {
        cout << "Enter temperature in fahrenheit: ";
        cin >> tempInFah;
    }
    void setData(float temp)
    {
        tempInFah = temp;
    }
    float FahrenheitToCelcius()
    {
        return (tempInFah - 32) * (5 / 9);
    }
    void showData()
    {
        cout << "Temperature in fahrenheit: " << tempInFah << endl;
    }
};

int main()
{
    Celcius c1;
    Fahrenheit f1;
    c1.setData();
    f1.setData();
    c1.showData();
    cout << "Temperature in Fahrenheit: " << c1.celciusToFahrenheit() << endl;
    f1.showData();
    cout << "Tempeartute in Celcius: " << f1.FahrenheitToCelcius() << endl;
    return 0;
}