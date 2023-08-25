#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void push(int x)
{
    q.push(x);
    for(int i=0;i<q.size()-1;i++)
    {
        q.push(q.front());
        q.pop();
    }
}
void pop()
{
    if(q.empty())
        cout<<"Queue is empty"<<endl;
    else
        q.pop();
}
int top()
{
    if(q.empty())
        return -1;
    return q.front();
}
int main()
{
    push(10);
    push(20);
    pop();
    cout<<top()<<endl;
    return 0;
}