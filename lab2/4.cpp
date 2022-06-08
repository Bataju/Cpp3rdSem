//Lab-2 Question-4

/*A function that passes two temperatures by reference and sets the larger of the two numbers 
to a value entered by user by using return by reference.*/

#include<iostream>

float& returnLargerTemperature(float& temp1, float& temp2);

int main()
{
    float temperature1, temperature2, setToThisTemp;
    std::cout<<"Enter temperature 1: ";
    std::cin>>temperature1;
    std::cout<<"Enter temperature 2: ";
    std::cin>>temperature2;
    std::cout<<"Enter the temperature you want to set the larger one to: ";
    std::cin>>setToThisTemp;
    std::cout<<"Before calling the function the tempeartures are "<<temperature1<<" and "<<temperature2<<"."<<std::endl;
    returnLargerTemperature(temperature1, temperature2) = setToThisTemp;
    std::cout<<"After calling the function the tempeartures are "<<temperature1<<" and "<<temperature2<<"."<<std::endl;
    return 0;
}

float& returnLargerTemperature(float& temp1, float& temp2)
{
    if(temp1>temp2)
        return temp1;
    else
        return temp2;
}