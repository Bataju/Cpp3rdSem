/*Write a class Date that overloads prefix and postfix operators to increase the Date object
by one day, while causing appropriate increments to the month and year
(use the appropriate condition for leap year). The prefix and postfix operators in the
Date class should behave exactly like the built-in increment operators.*/

#include <iostream>
using namespace std;

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y = 0, int m = 0, int d = 0):year(y), month(m), day(d){} // constructor
    int noOfDaysInAMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int isLeapYear();
    void displayDate();
    Date operator++();    // prefix
    Date operator++(int); // postfix - dummy integer
};

int Date::isLeapYear()
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else
            return 1;
    }
    else
        return 0;
}

void Date::displayDate()
{
    cout << setfill('0') << setw(4) << year << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(2) << day << endl;
    // year can be replaced by this->year
}

Date Date::operator++() // prefix
{
    if (isLeapYear() == 1)
        noOfDaysInAMonth[1] = 29;
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
    if (isLeapYear() == 1)
        noOfDaysInAMonth[1] = 29;
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
}

int main()
{
    Date d1(2021, 12, 31);

    cout << "Current date..." << endl;
    d1.displayDate();

    cout << "Postfix increment..." << endl;
    (d1++).displayDate(); // postfix i.e first display then increase
    cout << "New date..." << endl;
    d1.displayDate();

    cout << "Prefix increment..." << endl;
    (++d1).displayDate(); // prefix i.e firstt increase then display
    cout << "New date..." << endl;
    d1.displayDate();
    return 0;
}