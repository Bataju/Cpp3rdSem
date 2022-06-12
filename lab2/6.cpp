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

float newSalary(float oldSalary, int increment = 0)
{
    return (oldSalary + (static_cast<float>(increment) / 100) * oldSalary);
}
//(oldSalary + ((increment / 100) * oldSalary))
int main()
{
    float oldSalCEO, oldSalIO, oldSalSA, oldSalP;
    oldSalCEO = 35000;
    oldSalIO = 25000;
    oldSalSA = 24000;
    oldSalP = 18000;
    std::cout<<"OLD SALARIES i.e. 2009"<<std::endl;
    std::cout<<"Chief Executive Officer : Rs. "<<oldSalCEO<<std::endl
             <<"Information Officer : Rs.  "<<oldSalIO<<std::endl
             <<"System Analyst : Rs. "<<oldSalSA<<std::endl
             <<"Programmer : Rs. "<<oldSalP<<std::endl<<std::endl;
             
    std::cout<<"NEW SALARIES i.e. 2010"<<std::endl;
    std::cout<<"Chief Executive Officer : Rs. "<<newSalary(oldSalCEO, 9)<<std::endl
             <<"Information Officer : Rs.  "<<newSalary(oldSalIO, 10)<<std::endl
             <<"System Analyst : Rs. "<<newSalary(oldSalSA, 12)<<std::endl
             <<"Programmer : Rs. "<<newSalary(oldSalP, 12)<<std::endl;
    return 0;
}
