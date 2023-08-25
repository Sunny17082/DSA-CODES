#include <bits/stdc++.h>
using namespace std;
void display (int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insert (int a[],int n,int x,int y)
{
    n++;
    for (int i=n;i>=x;i--)
    {
        a[i]=a[i-1];
    }
    a[x-1]=y;
    display(a,n);
}
void delete_ (int a[],int n,int x)
{
    n--;
    for (int i=x-1;i<n;i++)
    {
        a[i]=a[i+1];
    }
    display (a,n);
}
void search (int a[],int n,int x)
{
    int flag=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]==x)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
    {
        cout<<"Search Successful"<<endl;
    }
    else
    {
        cout<<"Search Unsuccessful"<<endl;
    }
}
int main ()
{
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    display(a,n);
    insert (a,n,5,5);
    delete_ (a,n,2);
    search(a,n,5);
}