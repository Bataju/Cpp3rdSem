/*Assume that you want to check whether the number is prime or not.
Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks
if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.*/

#include <iostream>
#include <cmath>
using namespace std;

class Number
{
private:
    int number;

public:
    void setData()
    {
        cout << "Enter a number: ";
        cin >> number;
    }
    void setData(int num)
    {
        number = num;
    }
    int isPrime()
    {
        if (number <= 1)
            return -1; // neither
        for (int i = 2; i <= sqrt(number); i++)
        {
            if (number % i == 0)
                return 0; // composite
        }
        return 1; // prime
    }
};

int main()
{
    char choice = 'y';
    while (choice != 'n' && choice != 'N')
    {
        Number n;
        n.setData();
        if (n.isPrime() == 1)
            cout << "PRIME..." << endl;
        else if (n.isPrime() == 0)
            cout << "COMPOSITE..." << endl;
        else
            cout << "NEITHER..." << endl;
        cout << "Do you want to continue?(y or n): ";
        cin >> choice;
    }
    return 0;
}