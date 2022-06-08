//Lab-2 Question-2

/*A program using the function overloading that converts feet to inches. 
Use function with no argument, one argument and two arguments.
Decide yourself the types of arguments. Use pass by reference in any one of the function above.*/

#include<iostream>

float feetToInches();
float feetToInches(float num);
float feetToInches(const float &f, const float &i);

int main()
{
    float feet, inches, returnValue;
    std::cout<<"Enter feet: ";
    std::cin>>feet;
    std::cout<<"Enter inches: ";
    std::cin>>inches;
    std::cout<<"When no argument is passed"<<std::endl;
    returnValue = feetToInches();
    std::cout<<"When only one argument is passed"<<std::endl;
    returnValue = feetToInches(feet);
    std::cout<<feet<<" feet is "<<returnValue<<" inches."<<std::endl;
    std::cout<<"When two arguments are passed"<<std::endl;
    returnValue = feetToInches(feet, inches);
    std::cout<<feet<<" feet and "<<inches<<" inches make "<<returnValue<<" inches."<<std::endl; //feet = returnValue since it is passed by reference
    return 0;
}

float feetToInches()
{
    std::cout<<"No arguments passed."<<std::endl;
    return 1;
}

float feetToInches(float num)
{
    return num*12;
}

float feetToInches(const float &f, const float &i)
{
    return (f*12)+i;
}