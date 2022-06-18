#include<iostream>
#include<cmath>
using namespace std;

class Number
{
    private:
        int num;
    public:
        void setData(int n)
        {
            num = n;
        }

        int isPrime()
        {
            if(num <= 1)
                return -1;
            for(int i=2; i<=sqrt(num); i++)
            {
                if(num % i == 0)
                {
                    return 0;
                }
            }
            return 1;
        }
};

int main()
{
    char choice = 'y';
    int inputNum;
    while(choice != 'n' && choice != 'N')
    {
        Number n;
        cout<<"Enter a number: ";
        cin>>inputNum;
        n.setData(inputNum);
        if(n.isPrime() == 1)
        {
            cout<<"Prime.."<<endl;
        }
        else if(n.isPrime() == -1)
        {
            cout<<"Neither prime nor composite.."<<endl;
        }
        else
        {
            cout<<"Composite.."<<endl;
        }
        cout<<"Do you want to continue?(y or n): ";
        cin>>choice;
    }
    return 0;
}