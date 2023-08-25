#include <bits/stdc++.h>
using namespace std;
stack<int> s1;
stack<int> s2;
void enqueue(int x)
{
    s1.push(x);
}
void dequeue()
{
    if(s1.empty() && s2.empty())
        cout<<"Queue is empty"<<endl;
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    s2.pop();
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    return 0;
}