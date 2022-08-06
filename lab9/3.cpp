/*Modify the stack class given in the previous lab to add the exception when a user
tries to add an item while the stack is full and when the user tries to add the item
while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.*/

#include <iostream>
using namespace std;
const int MAX = 3;

template <class T>
class Stack
{
private:
    T st[MAX];
    int top;
public:
    class Demo{}; //for exception
    Stack();
    void push(T var);
    T pop();
};

template <class T>
Stack<T>::Stack()
{
    top = -1;
}

template <class T>
void Stack<T>::push(T var)
{
    if (top < MAX-1) //-1 0 and 1 must be accepted for MAX = 3 because they become 0, 1 and 2 indexes due to prefix
    {
        st[++top] = var;
    }
    else
    {
        throw Demo();
    }
}

template <class T>
T Stack<T>::pop()
{
    if(top >= 0)
    {
        return st[top--];
    }
    else
    {
        throw Demo();
    }
}

int main()
{
    Stack<float> s1;
    try
    {
        s1.push(111.1F);
        s1.push(222.2F);
        s1.push(333.3F);
        s1.push(444.4F);
    }
    catch(Stack<float>::Demo)
    {
        cout<<"Stack limit exceeded.."<<endl;
    }
    try
    {
        cout << "1 : " << s1.pop() << endl;
        cout << "2 : " << s1.pop() << endl;
        cout << "3 : " << s1.pop() << endl;
        cout << "4 : " << s1.pop() << endl;
    }
    catch(Stack<float>::Demo)
    {
        cout<<"Stack empty.."<<endl;
    }
    

    Stack<long> s2;
    try
    {
        s2.push(123123123L);
        s2.push(234234234L);
        s2.push(345345345L);
        s2.push(777777745L);
    }
    catch(Stack<long>::Demo)
    {
        cout<<"Stack limit exceeded.."<<endl;
    }
    
    try
    {
        cout << "1 : " << s2.pop() << endl;
        cout << "2 : " << s2.pop() << endl;
        cout << "3 : " << s2.pop() << endl;
        cout << "4 : " << s2.pop() << endl;
    }
    catch(Stack<long>::Demo)
    {
        cout<<"Stack empty.."<<endl;
    }
    return 0;
}