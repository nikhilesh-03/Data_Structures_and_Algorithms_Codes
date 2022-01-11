#include <bits/stdc++.h>
using namespace std;
#define Max 5

class temp
{
    int top;

public:
    int a[Max];
    temp() { top = -1; }
    void is_Empty();
    void push(int x);
    int pull();
    void peek();
};
void temp ::is_Empty()
{
    if (top == -1)
    {
        cout << "Stack is Empty" << endl;
    }
}

void temp ::push(int x)
{
    if (top >= (Max - 1))
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top = top + 1;
        a[top] = x;
        cout << x << " pushed into stack" << endl;
    }
    return;
}
int temp ::pull()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        top = top - 1;
        cout << "Element popped from Stack => ";
        return (a[top + 1]);
    }
}
void temp ::peek()
{
    cout << "Top element of stack " << a[top] << endl;
    if (top == (Max - 1))
    {

        cout << "Stack is full" << endl;
    }
}
int main()
{
    class temp stack;
    stack.is_Empty();
    stack.pull();
    stack.push(3);
    stack.push(4);
    stack.push(10);
    stack.push(13);
    stack.push(21);
    stack.peek();
    stack.push(34);
    cout << stack.pull() << endl;
    cout << stack.pull() << endl;
    stack.peek();
    return 0;
}