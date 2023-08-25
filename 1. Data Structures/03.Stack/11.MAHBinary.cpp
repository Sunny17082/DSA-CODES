#include <bits/stdc++.h>
using namespace std;
vector<int> NSL(vector<int> arr)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=0;i<arr.size();i++)
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
vector<int> NSR(vector<int> arr)
{
    vector<int> v;
    stack<pair<int,int>> s;
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(s.size()==0)
            v.push_back(arr.size());
        else if(s.size()>0 && s.top().first<arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
                s.pop();
            if(s.size()==0)
                v.push_back(arr.size());
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    return v;
}
int MAH(vector<int> arr)
{
    vector<int> v = NSR(arr);;
    vector<int> u = NSL(arr);
    int a=0;
    for(int i=0;i<v.size();i++)
    {
        v[i]=v[i]-u[i]-1;
        v[i]=v[i]*arr[i];
        a=max(v[i],a);
    }
    return a;
}
int maximumAreaRectangle(int arr[][100],int m,int n)
{
    vector<int> v;
    for(int j=0;j<n;j++)
        v.push_back(arr[0][j]);
    int MaxArea=MAH(v);
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
                v[j]=0;
            else
                v[j]+=arr[i][j];
        }
        MaxArea=max(MaxArea,MAH(v));
    }
    return MaxArea;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int a[100][100];
    for (int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {            
            cin>>a[i][j];
        }
    }
    cout<<"Maximum Area : "<<maximumAreaRectangle(a,m,n);
    return 0;
}