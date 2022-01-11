#include <iostream>
using namespace std;
#define Max 6

class circular_queue
{
    int front, rear;

public:
    int count = 0;
    int queue[Max];
    circular_queue() { front = -1, rear = -1; }
    bool queueisempty();
    void enqueue(int x);
    void dequeue();
    bool isqueuefull();
    void front_of_queue();
    void display_circularqueue();
};
bool circular_queue ::isqueuefull()
{
    if (((rear + 1) % Max == 0 && (front == 0) && (count == 0))||(((rear + 2) % Max == front) &&
     count!=0))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool circular_queue ::queueisempty()
{
    if (((rear + 1) % Max == 0 && (front == 0) && (count == Max)) || (front == (rear + 1)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void circular_queue ::enqueue(int x)
{
    if (isqueuefull())
    {
        cout << "Circular queue gets overflow under enqueue" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        queue[front] = x;
        cout << "The element that has been pushed into queue after enqueue :" << queue[front];
        cout << endl;
    }
    else
    {
        rear = (rear + 1) % Max;
        queue[rear] = x;
        cout << "The element that has been pushed into queue after enqueue :" << queue[rear];
        cout << endl;
    }
}
void circular_queue ::dequeue()
{
    if (queueisempty())
    {
        cout << "Queue underflow over dequeue" << endl;
    }
    else
    {
        count++;
        front = (front + 1) % Max;
        if (front==0){
            cout<<"The element that gets poped out from queue after dequeue :"<<queue[Max-front-1];
        }
        else{
            cout<<"The element that gets poped out from queue after dequeue :"<< queue[front - 1];        
        }
        cout << endl;
    }
}
void circular_queue ::front_of_queue()
{
    if (front >= 0 && front <= (Max - 1))
    {
        cout << "front_of_queue :" << queue[front]<<endl;
    }
}
void circular_queue :: display_circularqueue(){
    int front1=front,rear1=rear;
    cout<<"Display of Queue :";
    if (queueisempty()){
        cout<<"No element to show in queue"<<endl;
    }
    else{
        while (front1!=(rear1)){
            cout<<queue[front1]<<" ";
            front1=(front1+1)%Max;
        }
        cout<<queue[front1]<<endl;
    }
}
int main()
{
    class circular_queue fifo;
    fifo.enqueue(14);
    fifo.enqueue(22);
    fifo.enqueue(13);
    fifo.enqueue(-6);
    fifo.display_circularqueue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.display_circularqueue();
    fifo.enqueue(9);
    fifo.enqueue(20);
    fifo.enqueue(5);
    fifo.display_circularqueue();
    /*fifo.enqueue(1);
    fifo.enqueue(2);
    fifo.enqueue(3);
    fifo.enqueue(4);
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.display_circularqueue();
    fifo.enqueue(5);
    fifo.enqueue(11);
    fifo.enqueue(25);
    fifo.enqueue(15);
    fifo.enqueue(39);
    fifo.enqueue(71);
    fifo.display_circularqueue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.front_of_queue();
    fifo.dequeue();
    fifo.dequeue();
    fifo.enqueue(75);
    fifo.enqueue(51);
    fifo.display_circularqueue();
    fifo.front_of_queue();
    fifo.enqueue(100);
    fifo.dequeue();
    fifo.display_circularqueue();*/
    if (fifo.queueisempty())
    {
        cout << "Queue is Empty" << endl;
    }
    else if (fifo.isqueuefull())
    {
        cout << "Queue is full" << endl;
    }
    else{
        cout<<"Stack is neither empty nor full"<<endl;
    }
    return 0;
}
