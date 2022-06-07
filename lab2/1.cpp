//Lab-2 Question-1
/*A program to set a structure to hold a date (mm,dd and yy), 
assign values to the members of the structure and print out the values in the format 11/28/2004 by function.
Pass the structure to the function*/

#include<iostream>
#include<iomanip>

typedef struct Date
{
    int mm;
    int dd;
    int yyyy;
}Date;

void display(Date d);

int main()
{
    Date date;
    std::cout<<"Enter the month(eg: 11): ";
    std::cin>>date.mm;
    std::cout<<"Enter the date(eg: 24): ";
    std::cin>>date.dd;
    std::cout<<"Enter the year(eg: 2002): ";
    std::cin>>date.yyyy;
    display(date);
    return 0;
}

void display(Date d)
{
   std::cout<<std::setfill('0')<<std::setw(2)<<d.mm<<"/"<<std::setfill('0')<<std::setw(2)<<d.dd<<"/"<<std::setfill('0')<<std::setw(4)<<d.yyyy<<std::endl;
}