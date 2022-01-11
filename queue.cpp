#include <iostream>
using namespace std;
#define Max 7
class isqueue
{
    int front, rear;

public:
    int arr[Max];
    isqueue() { front = -1, rear = -1; }
    void queueisempty();
    void enqueue(int x);
    void dequeue();
    bool isqueuefull();
    void size_of_queue();
    void front_of_queue();
};
void isqueue ::queueisempty()
{
    if ((front == -1 && rear == -1) || (front == rear + 1))
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is still not empty" << endl;
    }
}
void isqueue::dequeue()
{
    if ((front == -1 && rear == -1) || (front == rear + 1))
    {
        cout << "Queue underflow under dequeue" << endl;
    }
    else if (front <= rear)
    {
        front = front + 1;
        if(front==1){
            cout <<"The element that gets eliminated from the Queue is :" << arr[front-1]<<endl;
        }
        else{
            cout <<"The element that gets eliminated from the Queue is :"<<arr[front - 1]<<endl;
            cout<<"Size of Queue after Dequeue :";
            size_of_queue();
        }
        return;
    }
}
void isqueue ::enqueue(int x)
{
    if (isqueuefull())
    {
        cout << "Queue overflow by enqueue" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        arr[front] = x;
        cout <<"New Element that has been pushed into Queue :"<<x<<endl;
        cout<<"Size of Queue after Enqueue :";
        size_of_queue();
    }
    else
    {
        ++rear;
        arr[rear] = x;
        cout <<"New Element that has been pushed into Queue :"<<x<<endl;
        cout<<"Size of Queue after Enqueue :";
        size_of_queue();
    }
    return;
}
bool isqueue ::isqueuefull()
{
    if (rear == (Max-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void isqueue ::size_of_queue()
{
    if (front == -1)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<(rear - front + 1)<<endl;
    }
}
void isqueue ::front_of_queue()
{
    if (front>=0 && front<=(Max-1))
    {
        cout << "Element at the Front of Queue :" << arr[front]<<endl;
    }
}
int main()
{
    class isqueue fifo;
    fifo.queueisempty();
    fifo.dequeue();
    fifo.enqueue(3);
    fifo.dequeue();
    fifo.enqueue(27);
    fifo.enqueue(11);
    fifo.dequeue();
    fifo.enqueue(83);
    fifo.enqueue(14);
    fifo.enqueue(99);
    fifo.enqueue(56);
    fifo.enqueue(41);
    fifo.enqueue(76);
    if (fifo.isqueuefull())
    {
        cout << "Queue is Full"<<endl;
    }
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    return 0;
}