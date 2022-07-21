#include <iostream>
using namespace std;
const int MAX = 5;

class classWithArray
{
private:
    int myArray[MAX];
public:
    classWithArray();
    void fillArray();
    int& operator[](int index);//index operator overload
};

classWithArray::classWithArray()
{
    for(int i=0; i<MAX; i++)
        myArray[i] = 0;
}

void classWithArray::fillArray()
{
    int inputArray[MAX];
    cout<<"Enter 5 integers to be stored in the array..."<<endl;
    for(int i=0; i<MAX; i++)
        cin>>inputArray[i];
    for(int i=0; i<MAX; i++)
        myArray[i] = inputArray[i];
}

int& classWithArray::operator[](int index)//returning reference so that it can be used as an lvalue
{
    return myArray[index];
}

int main()
{
    classWithArray c1;
    c1.fillArray();
    //c1.myArray[0] = 0; ERROR inaccesible
    c1[0] = 0; //can change it even though myArray is a private member
    cout<<"Displaying the contents of the array..."<<endl;
    for(int i=0; i<MAX; i++)
        cout<<c1[i]<<endl;//can directly access the array member using the object
    return 0;
}