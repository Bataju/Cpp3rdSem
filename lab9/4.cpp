/*Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.*/

#include<iostream>
using namespace std;

class Factorial
{
    private:
        float number;
    public:
        class NEGATIVE{};
        class FLOATINGPOINT{};
        void getNumber()
        {
            cout<<"Enter number: ";
            cin>>number;
        }
        void displayFactorial()
        {
            if(number<0)
                throw NEGATIVE();
            if(static_cast<int>(number) != number)
                throw FLOATINGPOINT();
            long int facto = 1;
            for(int i=1; i<=number; i++)
            {
                facto*=i;
            }
            cout<<facto<<endl;
        }
};

int main()
{
    Factorial f1;
    f1.getNumber();
    try
    {
        try
        {
            f1.displayFactorial();
        }
        catch(Factorial::NEGATIVE)
        {
            cout<<"The factorial of a negative number doesn't exist."<<endl;
            throw;
        }
        catch(Factorial::FLOATINGPOINT)
        {
            cout<<"The factorial of a floating point doesn't exist."<<endl;
            throw;
        }
    }
    catch(Factorial::NEGATIVE)
    {
        cout<<"Handling the exception rethrown."<<endl;
    }
    catch(...)
    {
        cout<<"Handling all the unhandled exceptions."<<endl;
    } 
    return 0;
}