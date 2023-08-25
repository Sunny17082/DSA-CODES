#include <bits/stdc++.h>
using namespace std;
queue<int> q1;
queue<int> q2;
void push(int x)
{
    q1.push(x);
}
void pop()
{
    if(q1.empty())
        cout<<"Stack is empty"<<endl;
    else
    {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> q=q1;
        q1=q2;
        q2=q;
    }
}
int top()
{
    if(q1.empty())
        return -1;
    else
    {
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int temp=q1.front();
        q1.pop();
        q2.push(temp);
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return temp;
    }
}
int main()
{
    push(10);
    push(20);
    pop();
    cout<<top()<<endl;
    return 0;
}