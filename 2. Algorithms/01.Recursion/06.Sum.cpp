#include <bits/stdc++.h>
using namespace std;
int sum (int n)
{
    if (n==0)
        return 0;
    return n+sum(n-1);
}
int main ()
{
    cout<<sum(5)<<endl;
    return 0;
}



// int sum(int n)
// {
// if(n==0)
// return 0;
// return sum(n-1)+n;
// }
// int Isum(int n)
// {
// int s=0,i;
// for(i=1;i<=n;i++)
// s=s+i;
// return s;
// }
// int main()
// {
// int r=sum(5);
// printf("%d ",r);
// return 0;
// }