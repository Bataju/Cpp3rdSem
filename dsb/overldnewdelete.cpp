#include <iostream>
using namespace std;

class Cpoint
{
private:
    int x, y;

public:
    Cpoint(int a = 0, int b = 0) : x(a), y(b) {}
    void display()
    {
        cout << "(" << this->x << " , " << this->y << ")" << endl;
    }
    void *operator new(size_t); // must have void* return type
    void *operator new[](size_t);
    void operator delete(void *); // must have void return type
    void operator delete[](void *);
};

/*size_t is essentially an unsigned integer
The parameter size will contain the number of bytes needed 
to hold the object being allocated.
size_t is passed by default by the class name.
*/
void *Cpoint::operator new(size_t size)
{
    cout<<size<<endl;
    cout << "Overloaded operator new called..." << endl;
    // Cpoint *ptr = ::new Cpoint;
    Cpoint *ptr = (Cpoint*)malloc(size);
    return ptr;
}

void *Cpoint::operator new[](size_t size)
{
    cout<<size<<endl;
    cout << "Overloaded operator new called..." << endl;
    //Cpoint *ptr = ::new Cpoint[size / sizeof(Cpoint)]; // size = sizeof(Cpoint) * n i.e. n = size/sizeof(Cpoint)
    Cpoint *ptr = (Cpoint*)malloc(size); 
    return ptr;
}

void Cpoint::operator delete(void *ptr)
{
    cout << "Overloaded operator delete called..." << endl;
    // ::delete (Cpoint *)ptr;
    free(ptr);
}

void Cpoint::operator delete[](void *ptr)
{
    cout << "Overloaded operator delete called..." << endl;
    // ::delete[](Cpoint *) ptr;
    free(ptr);
}

int main()
{
    Cpoint *p1, *p2;
    p1 = new Cpoint(2, 3);//size_t size will be 8
    p2 = new Cpoint[5];//size_t size will be 8*5 = 40
    (*p1).display();

    for (int i = 0; i < 5; i++)
    {
        p2[i] = Cpoint(i + 1, i + 1);
    }
    for (int i = 0; i < 5; i++)
    {
        p2[i].display();
    }
    delete p1;
    delete[] p2;
    return 0;
}