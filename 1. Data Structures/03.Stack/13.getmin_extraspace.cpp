#include <bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;
void push(int x)
{
    s.push(x);
    if(ss.size()==0 || ss.top()>=x)
        ss.push(x);
}
int pop()
{
    if(s.size()==0)
        return -1;
    int x=s.top();
    s.pop();
    if(ss.top()==x)
        ss.pop();
    return x;
}
int minstack()
{
    if(ss.size()==0)
        return -1;
    return ss.top();
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        push(a[i]);
    }
    cout<<minstack()<<endl;
    return 0;
}

