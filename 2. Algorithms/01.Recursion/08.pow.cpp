#include <bits/stdc++.h>
using namespace std;
int pow(int a,int b)
{
    if (b==0)
        return 1;
    return a*pow(a,b-1);
}
//faster
int pow1(int a,int b)
{
    if (b==0)
        return 1;
    if (b%2==0)
        return pow1(a*a,b/2);
    else
        return a*pow1(a*a,(b-1)/2);
}
int main ()
{
    cout<<pow(2,3)<<endl;
    cout<<pow1(2,3)<<endl;
    return 0;
}