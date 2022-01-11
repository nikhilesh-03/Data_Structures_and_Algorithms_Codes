#include<iostream>
using namespace std;
#include<stack>

class queue_using_stack{
    stack<int> s1,s2;
    public:
    void enqueue(int x);
    void dequeue();
    void transvere();
    bool isempty(){
        if (s1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

void queue_using_stack :: enqueue(int x){
    s1.push(x);
}

void queue_using_stack :: dequeue(){
    if(s1.empty()){
        cout<<"Queue underflow using dequeue"<<endl;
    }
    else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
}

void queue_using_stack :: transvere(){
    stack<int> s3=s1,s4;
    if(s3.empty()){
        cout<<"Queue underflow using dequeue"<<endl;
    }
    else{
        while(!s3.empty()){
            s4.push(s3.top());
            s3.pop();
        }
        while(!s4.empty()){
            cout<<s4.top()<<" ";
            s4.pop();
        }
        cout<<endl;
    }
}

int main(){
    queue_using_stack aditya;
    aditya.enqueue(2);
    aditya.enqueue(3);
    aditya.enqueue(11);
    aditya.enqueue(27);
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
    aditya.enqueue(31);
    aditya.enqueue(59);
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
    aditya.dequeue();
    aditya.transvere();
}