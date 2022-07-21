#include <iostream>
using namespace std;

class Bools
{
private:
    bool x;
public:
    Bools(bool xIn=false):x(xIn){} //default false
    bool operator && (Bools& obj2) //binary
    {
        return(this->x && obj2.x);
    }
    bool operator || (Bools& obj2) //binary
    {
        return(this->x || obj2.x);
    }
    bool operator ! () //unary
    {
        return(!(this->x));
    }
};

int main()
{
    Bools b1(true);
    Bools b2(false);
    cout<<boolalpha<<(b1&&b2)<<endl; //boolalpha for true and false instead of 0s n 1s
    cout<<(b1||b2)<<endl;
    cout<<(!b1)<<endl;
    return 0;
}