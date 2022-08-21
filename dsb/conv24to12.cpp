#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class HourFormat12;
class HourFormat24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    HourFormat24(int h=0, int m=0, int s=0):hours(h), minutes(m), seconds(s){}
    HourFormat24(HourFormat12);
    int returnHours(){return this->hours;}
    int returnMinutes(){return this->minutes;}
    int returnSeconds(){return this->seconds;}
    void display();
};

class HourFormat12
{
private:
    int hours;
    int minutes;
    int seconds;
    char amORpm[3];
public:
    HourFormat12(int h=0, int m=0, int s=0, const char* aORp=" "):hours(h), minutes(m), seconds(s)
    {
        strcpy(amORpm, aORp);
    }
    HourFormat12(HourFormat24);
    int returnHours(){return this->hours;}
    int returnMinutes(){return this->minutes;}
    int returnSeconds(){return this->seconds;}
    const char* returnAmOrPm(){return amORpm;}
    void display();
};

HourFormat24::HourFormat24(HourFormat12 twelve)//12 TO 24
{
    this->minutes = twelve.returnMinutes();
    this->seconds = twelve.returnSeconds();
    if(twelve.returnHours()<=12 && strcmp(twelve.returnAmOrPm(), "am")==0) //12:00 am to 11:59am
    {
        this->hours = twelve.returnHours() % 12; //so that it'll be zero for 12:00 am
    }
    if(twelve.returnHours()<=12 && strcmp(twelve.returnAmOrPm(), "pm")==0) //12:00pm to 11:59 pm
    {
        this->hours = 12 + twelve.returnHours() % 12;
    }
} 

HourFormat12::HourFormat12(HourFormat24 twentyfour)
{
    this->minutes = twentyfour.returnMinutes();
    this->seconds = twentyfour.returnSeconds();
    if(twentyfour.returnHours() < 12) //00:00 to 11:59
    {
        this->hours = (twentyfour.returnHours()==0?12:twentyfour.returnHours());//0 to 12 others same
        strcpy(this->amORpm, "am");
    }
    if(twentyfour.returnHours() >= 12 && twentyfour.returnHours() < 24) //12:00 to 23:59
    {
        this->hours = (twentyfour.returnHours()==12?12:twentyfour.returnHours()%12);//12 to 12 others mod 12
        strcpy(this->amORpm, "pm");
    }
}

void HourFormat24::display()
{
    cout<<"24 hour format.."<<endl;
    cout<<setw(2)<<setfill('0')<<this->hours<<":"<<setw(2)<<this->minutes<<":"<<setw(2)<<this->seconds<<endl;
}

void HourFormat12::display()
{
    cout<<"12 hour format.."<<endl;
    cout<<setw(2)<<setfill('0')<<this->hours<<":"<<setw(2)<<this->minutes<<":"<<setw(2)<<this->seconds<<" "<<this->amORpm<<endl;
}

int main()
{
    HourFormat24 h24obj1(23, 51, 42), h24obj2;
    HourFormat12 h12obj1, h12obj2(12, 0, 0, "am");
    
    h12obj1 = h24obj1;
    cout<<"Time 1.."<<endl;
    h24obj1.display();
    h12obj1.display();

    h24obj2 = h12obj2;
    cout<<"Time 2.."<<endl;
    h24obj2.display();
    h12obj2.display();
    return 0;
}