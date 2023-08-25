#include <bits/stdc++.h>
using namespace std;
vector<int> nearestGreaterToRight(int a[],int n)
{
    vector<int> v;
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top()>a[i])
            v.push_back(s.top());
        else if(s.size()>0 && s.top()<a[i])
        {
            while(s.size()>0 && s.top()<=a[i])
                s.pop();
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(a[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    v=nearestGreaterToRight(a,n);
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<" ";
    return 0;
}