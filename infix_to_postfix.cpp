#include <iostream>
using namespace std;

class postfix
{
public:
    int top;
    int len;
    int arr[100000];
    postfix(int length)
    {
        top = -1;
        len = length;
    }
    int pop();
    void push(char x);
    int _top();
    void stack();
    int top_element();
};
void postfix ::push(char x)
{
    top = top + 1;
    arr[top] = x;
    return;
}
int postfix ::pop()
{
    top = top - 1;
    return arr[top + 1];
}
int postfix ::top_element()
{
    if (top < 0)
    {
        return -1;
    }
    return (arr[top]);
}

int postfix ::_top()
{
    return top;
}
void postfix ::stack()
{
    for (int j = top; j >= 0; j--)
    {
        cout << char(arr[j]);
    }
    return;
}
int precedence_of_operators(char x)
{
    if (x == '(' || x == ')')
    {
        return 4;
    }
    else if (x == '^')
    {
        return 3;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string expression;
    cout << "Enter The Expression:-" << endl;
    cin >> expression;
    int a = expression.length();
    postfix s(a);
    for (int i = 0; i < a; i++)
    {
        if (expression[i] >= 65 && expression[i] <= 90 || expression[i] >= 97 && expression[i] <= 122)
        {

            cout << expression[i];
        }
        else
        {
            if (s._top() == -1 || s.top_element() == '(')
            {
                s.push(expression[i]);
            }
            else if (expression[i] == '(')
            {
                s.push('(');
            }
            else if (expression[i] == ')')
            {
                while (s.top_element() != '(')
                {
                    cout << char(s.pop());
                }
                //s.pop();
            }
            else if ((precedence_of_operators(expression[i])) > precedence_of_operators(s.top_element()))
            {
                s.push(expression[i]);
            }
            else if ((precedence_of_operators(expression[i])<precedence_of_operators(s.top_element())) && s.top_element()!='(')
            {
                while (((precedence_of_operators(expression[i])) < (precedence_of_operators(s.top_element()))))
                {
                    cout << char(s.pop());
                }
                if (((precedence_of_operators(expression[i])) > (precedence_of_operators(s.top_element()))))
                {
                    s.push(expression[i]);
                }
                else if (((precedence_of_operators(expression[i])) == (precedence_of_operators(s.top_element()))))
                {
                    cout << char(s.top_element());
                    s.pop();
                    s.push(expression[i]);
                }
            }
            else if ((precedence_of_operators(expression[i])<precedence_of_operators(s.top_element())) && s.top_element()=='('){
                s.push(expression[i]);
            }
            else if ((precedence_of_operators(expression[i])) == (precedence_of_operators(s.top_element())))
            {
                if (precedence_of_operators(s.top_element()) == 3)
                {
                    s.push(expression[i]);
                }
                else
                {
                    cout << char(s.pop());
                    s.push(expression[i]);
                }
            }
        }
        s.stack();
        cout<<endl;
    }
    s.stack();
    return 0;
}