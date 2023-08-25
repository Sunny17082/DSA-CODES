#include <bits/stdc++.h>
using namespace std;
void insert(int a[],int n,int x)
{
    int i=n-1;
    while (a[i]>x)
    {
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=x;
    for (int i=0;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main ()
{
    int n;
    cin>>n;
    int a[10];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    insert(a,n,x);
}