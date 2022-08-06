/*Create a function called sum() that returns the sum of the elements of an array. 
Make this function into a template so it will work with any numerical type. Write a 
program that applies this function to data of various types.*/

#include<iostream>
using namespace std;

template<class T>
T sum(T array[], int size)
{
    T sum=0;
    for(int i=0; i<size; i++)
    {
        sum+=array[i];
    }
    return sum;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    float floatArray[] = {1.1, 2.5, 6.5, 1.2};
    cout<<"Sum of integer array: "<<sum(intArray, 5)<<endl;
    cout<<"Sum of float array: "<<sum(floatArray, 4)<<endl;
    return 0;
}