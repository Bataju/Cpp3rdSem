/*Following are some useful facts about overloading of [].
1) Overloading of [] may be useful when we want to check for index out of bound.
2) We must return by reference in function because an expression like “arr[i]” 
can be used an lvalue.*/

const int MAX = 10;

#include<iostream>
#include<cstdlib>
using namespace std;

class safeArray
{
    private:
        int arr[MAX];
    public:
        safeArray(int*, int);
        int & operator [](int);
};

safeArray::safeArray(int * inputArr, int size)
{
    for(int i=0; i<size; i++)
    {
        arr[i] = inputArr[i];
    }
}

int & safeArray::operator[](int index)
{
    if(index<0 || index>=MAX)
    {
        cout<<"Index out of bound..."<<endl;
        exit(0);
    }
    return arr[index];
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    safeArray array1(array, 5);
    array1[0] = 9;
    int number = array1[4];
    cout<<array1[0]<<"\t"<<number<<endl;
    array1[11] = 6;//out of bound
    return 0;
}