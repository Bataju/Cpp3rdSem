/*Write a class Date that overloads prefix and postfix operators to increase the Date object
by one day, while causing appropriate increments to the month and year
(use the appropriate condition for leap year). The prefix and postfix operators in the
Date class should behave exactly like the built-in increment operators.*/

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;
    int noOfDaysInAMonth[12];

public:
    Date(int y=0, int m=0, int d=0); //constructor
    void displayDate()
    {
        cout << setfill('0') << setw(4) << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << endl;
    //year can be replaced by this->year
    }
    Date operator++();    // prefix
    Date operator++(int); // postfix - dummy integer
};

Date::Date(int y, int m, int d)// (int y=0, int m=0, int d=0) can't to this here beacuse default arguments are already specified previously
{
    year = y;
    month = m;
    day = d;
    int isLeapYear;
    int daysInFeb;

    //checking if the year is a leap year and setting the number of days in the constructor itself
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0) isLeapYear = 1;
            else isLeapYear = 0;
        }
        else isLeapYear = 1;
    }
    else isLeapYear = 0;

    if (isLeapYear == 1) daysInFeb = 29; //number of days in february according to the year
    else daysInFeb = 28;

    int tempArray[] = {31, daysInFeb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //number of days in all the months
    for (int i = 0; i < 12; i++)
    {
        noOfDaysInAMonth[i] = tempArray[i];
    }
    // doin this because we can't assign array which was already declared from member initialiser list
}

Date Date::operator++() // prefix
{
    day++;
    if (day > noOfDaysInAMonth[month - 1])
    {
        month++;
        day = 1;
    }
    if (month > 12)
    {
        year++;
        month = 1;
    }
    return *this;
}

Date Date::operator++(int) // postfix
{
    Date temp = *this;
    day++;
    if (day > noOfDaysInAMonth[month - 1])
    {
        month++;
        day = 1;
    }
    if (month > 12)
    {
        year++;
        month = 1;
    }
    return temp;
    ;
}

int main()
{
    Date d1(2021, 12, 31);
    
    cout<<"Current date..."<<endl;
    d1.displayDate();

    cout<<"Postfix increment..."<<endl;
    (d1++).displayDate(); // postfix i.e first display then increase
    cout<<"New date..."<<endl;
    d1.displayDate();

    cout<<"Prefix increment..."<<endl;
    (++d1).displayDate(); // prefix i.e firstt increase then display
    cout<<"New date..."<<endl;
    d1.displayDate();
    return 0;
}