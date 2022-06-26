/*    Assume that an object represents an employee report that contains information like employee id,
total bonus, total overtime in a particular year. Use an array of objects to represent n employees' reports.
Write a program that displays the report. Use setpara() member function to set report attributes by passing
the arguments and member function displayreport() to show the report according to the parameter passed.
Display the report in the following format.

An employee with ... ... ... has received Rs ... ... ...as a bonus

and

had worked ... ... ... hours as overtime in the year ... ... ...*/

#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeId;
    float totalBonus;
    float totalOvertime;
    int year;

public:
    void setpara(int eid, float bonus, float overtime, int y = 2022)
    {
        employeeId = eid;
        totalBonus = bonus;
        totalOvertime = overtime;
        year = y;
    }

    void displayReport()
    {
        cout << endl
             << "An employee with " << employeeId << " has received Rs. " << totalBonus << " as a bonus"
             << endl
             << "and" << endl
             << "had worked " << totalOvertime << " hours as overtime in the year " << year << endl;
    }
};

int main()
{
    int numberOfEmployee;
    int empId, year;
    float bonus, overtime;
    cout << "Enter the number of employees: ";
    cin >> numberOfEmployee;
    Employee *e;
    e = new Employee[numberOfEmployee];
    for (int i = 0; i < numberOfEmployee; i++)
    {
        cout << "Enter employee id: ";
        cin >> empId;
        cout << "Enter the total bonus: ";
        cin >> bonus;
        cout << "Enter the total overtime: ";
        cin >> overtime;
        cout << "Enter the year: ";
        cin >> year;
        cout << endl;
        (e + i)->setpara(empId, bonus, overtime, year);
    }

    for (int i = 0; i < numberOfEmployee; i++)
    {
        e[i].displayReport();
    }
    delete[] e;
    return 0;
}