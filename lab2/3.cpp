//Lab-2 Question-3

/*Define two namespaces: Square and Cube. 
In both the namespaces, define an integer variable named "num" and a function named "fun". 
The "fun" function in "Square" namespace, should return the square of an integer passed as an argument 
while the "fun" function in "Cube" namespace, should return the cube of an integer passed as an argument. 
In the main function, set the integer variables "num" of both the namespaces with different values. 
Then, compute and print the cube of the integer variable "num" of the "Square" namespace using the "fun" 
function of the "Cube" namespace and the square of the integer variable "num" of the "Cube" namespace 
using the "fun" function of the "Square" namespace.*/

#include<iostream>

namespace Square
{
    int num;
    int fun()
    {
        return num*num;
    }
}

namespace Cube
{
    int num;
    int fun()
    {
        return num*num*num;
    }
}

int main()
{
    int number;
    std::cout<<"Enter the number you want the square of: ";
    std::cin>>Square::num;
    std::cout<<"Enter the number you want the cube of: ";
    std::cin>>Cube::num;
    std::cout<<"Square of "<<Square::num<<" is "<<Square::fun()<<"."<<std::endl;
    std::cout<<"Cube of "<<Cube::num<<" is "<<Cube::fun()<<"."<<std::endl;
    return 0;
}
