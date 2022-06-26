/*Write a program that has a class to represent time. 
The class should have constructors to initialize data members hour, minute, and second 
to 0 and to initialize them to values passed as arguments. 
The class should have a member function to add time objects and return the result 
as a time object. There should be functions to display time in 12-hour and 24-hour format.*/

#include<iostream>
#include<iomanip>
#include<cstring>

using namespace std;

class Time
{
    private:
        int hour;
        int minute;
        int second;

    public:
        Time()
        {
            hour = 0;
            minute = 0;
            second = 0;
        }

        Time(int h, int m, int s)
        {
            hour = h;
            minute = m;
            second = s;
        }

        Time addTimes(Time t2)
        {
            Time t3;
            t3.second = second + t2.second;
            t3.minute = minute + t2.minute;
            t3.hour = hour + t2.hour;
            if(t3.second > 60)
            {
                t3.minute++;
                t3.second = t3.second - 60;
            }
            if(t3.minute > 60)
            {
                t3.hour ++;
                t3.minute = t3.minute - 60;
            }
            if(t3.hour > 23)
            {
                t3.hour = t3.hour % 24;
            }
            return t3;
        }

        void display24hourFormat()
        {
            cout<<"Displaying 24 hour format"<<endl;
            cout<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setfill('0')<<setw(2)<<second<<endl;
        }

        void display12hourFormat()
        {
            cout<<"Displaying 12 hour format"<<endl;
            char AmOrPm[3];
            if (hour>12 || (hour == 12 && minute > 0) || (hour == 12 && minute == 0 && second > 0))
                strcpy(AmOrPm, "pm");
            else
                strcpy(AmOrPm, "am");
            cout<<setfill('0')<<setw(2)<<(hour==12?12:hour%12)<<":"<<setfill('0')<<setw(2)<<minute<<":"<<setfill('0')<<setw(2)<<second<<" "<<AmOrPm<<endl;
        }
        //(hour==12?12:hour%12) if it is 12 pm then display 12 not hour % 12 i.e 0
};

int main()
{
    Time t1(00, 54, 58);
    Time t2(23, 59, 59);
    Time t3;
    t3 = t1.addTimes(t2);
    cout<<endl<<"Time t1"<<endl;
    t1.display24hourFormat();
    t1.display12hourFormat();
    cout<<endl<<"Time t2"<<endl;
    t2.display24hourFormat();
    t2.display12hourFormat();
    cout<<endl<<"Time t3 = t1 + t2"<<endl;
    t3.display24hourFormat();
    t3.display12hourFormat();
    return 0;
}