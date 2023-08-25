#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    char *a;
    int size;
    int top;
    Stack(int size)
    {
        this->size=size;
        a= new char[size];
        top=-1;
    }
    void push(char value)
    {
        if (top==size-1)
        {
            cout<<"Stack OverFlow"<<endl;
        }
        else
        {
            top++;
            a[top]=value;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack UnderFlow"<<endl;
        }
        else
        {
            top--;
        }
    }
    bool empty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string str;
    cin>>str;
    Stack s(50);
    for (int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='(')
        s.push(ch);
        else if (ch==')')
        {
            if (s.empty())
                cout<<"FALSE"<<endl;
            s.pop();
        }
    }
    if (s.empty())
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    return 0;
} 