#include<iostream>
using namespace std;
#include<queue>

class stack_using_queue{
    queue<int> q1,q2;
    public:
    int top(){
        return q1.back();
    }
    void push(int x){
        q1.push(x);
    }
    void pop();
    bool is_empty(){
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    void trasverse();
};

void stack_using_queue :: pop(){
    if(q1.empty()){
        cout<<"Stack underflow dequeue"<<endl;
    }
    else{
        while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
        }
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
}

void stack_using_queue :: trasverse(){
    queue<int> q3=q1;
    if(q3.empty()){
        cout<<"Queue can't be transversed as it is empty "<<endl;
    }
    else{
        while(!q3.empty()){
            cout<<q3.front()<<" ";
            q3.pop();
        }
        cout<<endl;
    }
}

int main(){
    stack_using_queue aditya;
    aditya.push(3);
    aditya.push(11);
    aditya.push(27);
    aditya.push(90);
    aditya.trasverse();
    cout<<"The top element of stack "<<aditya.top()<<endl;
    aditya.pop();
    aditya.trasverse();
    cout<<"The top element of stack "<<aditya.top()<<endl;
    aditya.push(51);
    aditya.trasverse();
    cout<<"The top element of stack "<<aditya.top()<<endl;
    aditya.pop();
    aditya.trasverse();
    cout<<"The top element of stack "<<aditya.top()<<endl;
    aditya.pop();
    aditya.pop();
    aditya.trasverse();
    cout<<"The top element of stack "<<aditya.top()<<endl;
    aditya.pop();
    aditya.trasverse();
    aditya.pop();
}