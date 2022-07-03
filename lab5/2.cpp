/*Write a class to store x, y, and z coordinates of a point in three-dimensional space.
Overload addition and subtraction operators for addition and subtraction of two coordinate objects.
Implement the operator functions as non-member functions (friend operator functions).*/

#include <iostream>
using namespace std;

class ThreeDCoordinate
{
private:
    float x;
    float y;
    float z;

public:
    ThreeDCoordinate(float xIn = 0, float yIn = 0, float zIn = 0) : x(xIn), y(yIn), z(zIn) {}

    void display3dCoordinates()
    {
        cout << "(" << this->x << " , " << this->y << " , " << this->z << ")" << endl; // using this pointer works for nameless objects as well
    }

    friend ThreeDCoordinate operator+(ThreeDCoordinate c1, ThreeDCoordinate c2);           
    friend ThreeDCoordinate operator-(ThreeDCoordinate c1, ThreeDCoordinate c2); 
};

ThreeDCoordinate operator+(ThreeDCoordinate c1, ThreeDCoordinate c2)
{
    return ThreeDCoordinate(c1.x + c2.x, c1.y + c2.y, c1.z + c2.z);
}

ThreeDCoordinate operator-(ThreeDCoordinate c1, ThreeDCoordinate c2)
{
    return ThreeDCoordinate(c1.x - c2.x, c1.y - c2.y, c1.z - c2.z);
}

int main()
{
    ThreeDCoordinate A(1, 2, 3);
    ThreeDCoordinate B(4, 5, 6);
    cout << "A + B = ";
    (A + B).display3dCoordinates();
    cout << "A - B = ";
    (A - B).display3dCoordinates();
    return 0;
}