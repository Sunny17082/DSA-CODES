#include <bits/stdc++.h>
using namespace std;
vector<int> NSL(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top().first<arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    return v;
}
vector<int> NSR(int arr[],int n)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
            v.push_back(n);
        else if(s.size()>0 && s.top().first<arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(n);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}
int MAH(int arr[],int n)
{
    vector<int> v = NSR(arr,n);
    vector<int> u = NSL(arr,n);
    int a=0;
    for(int i=0;i<v.size();i++)
    {
        v[i]=v[i]-u[i]-1;
        v[i]=v[i]*arr[i];
        a=max(v[i],a);
    }
    return a;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Maximum Area : "<<MAH(a,n);
    return 0;
}