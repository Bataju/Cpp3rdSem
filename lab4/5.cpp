/*Write a program that illustrates the following relationship and comment on them. 

i) const_object.non_const_mem_function

ii) const_object.const_mem_function

iii) non_const_object.non_const_mem_function

iv) non_const_object.const_mem_function*/

#include<iostream>
#include<cstring>
using namespace std;

class Car
{
    private:
        string brand;
        int yearOfManufacture;
    public:
        Car()//default constructor
        {
            brand = "Mercedes";
            yearOfManufacture = 2001;
        }

        void setData()
        {
            cout<<"Enter the brand name: ";
            cin>>brand;
            cout<<"Enter the year of manufacture: ";
            cin>>yearOfManufacture;
        }

        void displayData () const
        {
            cout<<"Brand : "<<brand<<endl
                <<"Year of manufacture : "<<yearOfManufacture<<endl;
        }
};

int main()
{
    Car c1; //non constant object
    c1.setData(); //nonconstant object calling no constant function
    c1.displayData(); //nonconstant object calling constant function
    const Car c2; //constant object
    // c2.setData();//constant object calling non constant function
    c2.displayData();//constant object calling constant function
    return 0;
}