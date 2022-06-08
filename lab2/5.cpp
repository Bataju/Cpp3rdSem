//Lab-2 Question-5

/*Assume that employee will have to pay 10 percent income tax to the government. 
Ask user to enter the employee salary. Use inline function to display the net payment to the employee by the company.*/

#include<iostream>

inline float netPayment(float sal);

int main()
{
    float salary;
    std::cout<<"Enter your salary: ";
    std::cin>>salary;
    std::cout<<"After the deduction of income tax, you will receive Rs. "<<netPayment(salary)<<"."<<std::endl;
    return 0;
}

inline float netPayment(float sal)
{
    return 0.9*sal;
}