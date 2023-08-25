#include <bits/stdc++.h>
using namespace std;
void reverse (int a[],int n)
{
    int l=0,h=n-1;
    for (int i=0;i<n/2;i++)
    {
        swap (a[l],a[h]);
        l++;
        h--;
    }
    for (int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
    reverse (a,n);
}