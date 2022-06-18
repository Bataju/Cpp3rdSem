/*Assume that an object represents an employee report that contains information like employee id, 
total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports. 
Write a program that displays the report. Use setpara() member function to set report attributes 
by passing the arguments and member function displayreport() to show the report according to the parameter passed. 
Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus

and

had worked ... ... ... hours as overtime in the year ... ... ...*/

#include<iostream>
using namespace std;

class Employee
{
    private:
        int employeeId;
        float totalBonus;
        int year;
        float totalOvertime;
    public:
        void setPara(int eId, float totalBon, int y, float totalOT)
        {
            employeeId = eId;
            totalBonus = totalBon;
            year = y;
            totalOvertime = totalOT;
        }
        void displayReport()
        {
            cout<<endl<<"An employee with employee ID "<<employeeId<<" has received Rs. "<<totalBonus<<" as a bonus."<<endl
                <<"and"<<endl<<"had worked "<<totalOvertime<<" hours as overtime in the year "<<year<<"."<<endl;
        }
};

int main()
{
    Employee e[3];
    e[0].setPara(554, 85000, 2020, 98);
    e[0].displayReport();
    e[1].setPara(555, 74000, 2020, 75);
    e[1].displayReport();
    e[2].setPara(556, 90000, 2020, 108);
    e[2].displayReport();
    return 0;
}
