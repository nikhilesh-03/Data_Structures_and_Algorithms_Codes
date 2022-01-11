// DEQUEUE USING CIRCULAR ARRAY 
#include<iostream>
using namespace std;
#define MAX 7

class DEqueue {
    int rear,front;
public:
    int arr[MAX];
    DEqueue() {rear=-1,front=-1;}
    void enqueue_rear(int x);
    void dequeue_front();
    void enqueue_front(int y);
    void dequeue_rear();
    void display_DEqueue();
    void peek();
    bool is_empty();
    bool is_full();
};

bool DEqueue :: is_empty(){
    if (front==-1 && rear==-1){   // Remember when front==rear , then only one element left.
        return true;               // Thus at that situation we always do front==1 and rear=-1
    }
    else{
        return false;
    }
}
bool DEqueue :: is_full(){
    if ((front==0 && rear==(MAX-1)) || (front==rear+1)){
        return true;
    }
    else{
        return false;
    }
}

void DEqueue :: enqueue_rear(int x){
    if (is_full()){
        cout<<"DEqueue gets overflow under enqueue_back"<<endl;
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[rear]=x;
        cout<<"Element pushed into back of dequeue due to enqueue rear =>"<< x<<endl;
    }
    else{
        rear=(rear+1)%MAX;
        arr[rear]=x;
        cout<<"Element pushed into back of dequeue due to enqueue rear =>"<< x<<endl;
    }
}
void DEqueue :: enqueue_front(int y){
    if (is_full()){
        cout<<"DEqueue gets overflow under enqueue_front"<<endl;
    }
    if (front==-1 && rear==-1){
        front++;
        rear++;
        arr[front]=y;
    }
    else if(front!=0){
        front--;
        cout<<"Element pushed into front of dequeue due to enqueue front =>"<< y<<endl;
        arr[front]=y;
    }
    else if(front==0){
        front=MAX-1;
        cout<<"Element pushed into front of dequeue due to enqueue front =>"<< y<<endl;
        arr[front]=y;
    }
}
void DEqueue :: dequeue_rear(){
    if (is_empty()){
        cout<<"DEqueue underflow over dequeue_back"<<endl;
    }
    else if (rear==front){
        cout<<"Element popped after Dequeue_rear => "<<arr[rear]<<endl;
        rear=-1;
        front=-1;
    }
    else if(rear!=0){
        cout<<"Element popped from back after Dequeue_rear => "<<arr[rear]<<endl;
        rear--;
    }
    else if(rear==0){
        cout<<"Element popped from back after Dequeue_rear => "<<arr[rear]<<endl;
        rear=MAX-1;        
    }
}
void DEqueue :: dequeue_front(){
    if(is_empty()){
        cout<<"DEqueue underflow over dequeue_back"<<endl;        
    }
    else if(front==rear){
        cout<<"Element popped from front after Dequeue_front => "<<arr[front]<<endl;
        front=(-1);
        rear=(-1);
    }
    else{
        cout<<"Element popped from front after Dequeue_front => "<<arr[front]<<endl;
        front=(front+1)%MAX;
    }
}

void DEqueue :: display_DEqueue(){
    int front1 = front, rear1 = rear;
    if (is_empty())
    {
        cout << "No element to show in queue since its empty " << endl;
    }
    else
    {
        cout << "Display of circular queue :";
        while (front1 != rear1)
        {
            cout << arr[front1] <<" ";
            front1 = (front1 + 1) % MAX;
        }
        cout << arr[front1] << endl;
    }
}
void DEqueue :: peek(){
    cout<<"The front and rear index of the dequeue => "<<front<<" and "<<rear<<endl;
    cout<<"The front and rear element of the current Dequeue => "<<arr[front]<<" and "<<arr[rear]<<endl;
}

int main(){
    DEqueue nikh;
    if(nikh.is_empty()){
        cout<<"DEqueue is Empty"<<endl;
    }
    nikh.enqueue_rear(2);
    nikh.dequeue_front();
    nikh.enqueue_rear(7);
    nikh.enqueue_front(4);
    nikh.display_DEqueue();
    nikh.enqueue_rear(11);
    nikh.display_DEqueue();
    nikh.dequeue_front();
    nikh.display_DEqueue();
    nikh.enqueue_rear(-5);
    nikh.display_DEqueue();
    nikh.enqueue_front(34);
    nikh.display_DEqueue();
    nikh.dequeue_rear();
    nikh.enqueue_rear(29);
    nikh.display_DEqueue();
    nikh.peek();
    if(nikh.is_full()){
        cout<<"Dequeue is full"<<endl;
    }
    nikh.enqueue_front(12);
    nikh.display_DEqueue();
    nikh.peek();
    nikh.enqueue_front(21);
    nikh.enqueue_front(90);
    nikh.display_DEqueue();
    nikh.peek();
    if (nikh.is_full()){
        cout<<"DEqueue gets full"<<endl;
    }
    return 0;
}