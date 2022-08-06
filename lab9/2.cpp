/*Write a class template for queue class. Assume the programmer using the queue won't make mistakes, 
like exceeding the capacity of the queue or trying to remove an item when the queue is empty. 
Define several queues of different data types and insert and remove data from them.*/

#include<iostream>
#include<cstdlib>
using namespace std;
const int MAX = 100;

template<class T>
class Queue//fifo
{
private:
    T array[MAX];
    int size;
public:
    Queue();
    void add(T var);
    T remove();
};

template<class T>
Queue<T>::Queue()
{
    size = -1;
}

template<class T>
void Queue<T>::add(T var)
{
    if(size >= MAX)
    {
        cout<<"Queue is full..."<<endl;
        exit(0);
    }
    array[++size] = var;
}

template<class T>
T Queue<T>::remove()
{
    if(size < 0)
    {
        cout<<"Queue is empty.."<<endl;
        exit(0);
    }
    T tempStore = array[0];
    for(int i=0; i<size; i++)
    {
        array[i] = array[i+1];
    }
    size--;
    return tempStore;
}

int main()
{
    Queue<int> q1;
    Queue<float> q2;
    cout<<"Integer queue.."<<endl;
    q1.add(1);
    q1.add(2);
    q1.add(3);
    cout<<"First pop : "<<q1.remove()<<endl;;
    cout<<"Second pop : "<<q1.remove()<<endl;;
    cout<<"Third pop : "<<q1.remove()<<endl<<endl;

    cout<<"Float queue.."<<endl;
    q2.add(1.5);
    q2.add(6.3);
    q2.add(7.4);
    cout<<"First pop : "<<q2.remove()<<endl;
    cout<<"Second pop : "<<q2.remove()<<endl;
    cout<<"Third pop : "<<q2.remove()<<endl;
}