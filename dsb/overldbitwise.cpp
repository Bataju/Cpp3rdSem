#include <iostream>
using namespace std;

class Integer
{
private:
    int number;
public:
    Integer(int n=0):number(n){}
    int operator &(Integer& obj2);//bitwise and
    int operator |(Integer& obj2);//bitwise or
    int operator ^(Integer& obj2);//bitwise xor
    int operator <<(Integer& obj2);//left shift
    int operator >>(Integer& obj2);//right shift
    int operator ~();//bitwise not - unary and hence no argument
};

int Integer::operator&(Integer& obj2)
{
    return (this->number & obj2.number);
}
int Integer::operator|(Integer& obj2)
{
    return (this->number | obj2.number);
}
int Integer::operator^(Integer& obj2)
{
    return (this->number ^ obj2.number);
}
int Integer::operator<<(Integer& obj2)
{
    return (this->number << obj2.number);
}
int Integer::operator>>(Integer& obj2)
{
    return (this->number >> obj2.number);
}
int Integer::operator~()
{
    return ~(this->number);
}

int main()
{
    Integer i1(7);
    Integer i2(15);
    cout<<(i1&i2)<<endl
        <<(i1|i2)<<endl
        <<(i1^i2)<<endl
        <<(i1<<i2)<<endl
        <<(i1>>i2)<<endl
        <<~(i1)<<endl;
    return 0;
}