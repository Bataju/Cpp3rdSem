//Lab-2 Question-6

/*A program that displays the current monthly salary of chief executive officer, 
information officer, and system analyst, programmer that has been increased by 9, 10, 12, and 12 percentages 
respectively in year 2010. Let us assume that the salaries in year 2009 are
Chief executive officer Rs. 35000/m
Information officer Rs. 25000/m
System analyst Rs. 24000/m
Programmer Rs. 18000/m
Make a function that takes two arguments; one salary and the other increment. Use proper default argument.*/

#include<iostream>

using namespace std;

float displayCurrentSalary(float sal, int increment=12)
{
    return (sal+((float)increment/100) * sal);
}

int main()
{
    float salCEO=35000, salIO=25000, salSA=24000, salPro=18000;
    cout<<"The increased salaries: "<<endl;
    cout<<"Chief executive officer Rs. "<<displayCurrentSalary(salCEO, 9)<<endl;
    cout<<"Information Officer Rs. "<<displayCurrentSalary(salIO, 10)<<endl;
    cout<<"System Analyst Rs. "<<displayCurrentSalary(salSA)<<endl;
    cout<<"Progarmmer Rs. "<<displayCurrentSalary(salPro)<<endl;
    return 0;
}