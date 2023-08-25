#include <bits/stdc++.h>
using namespace std;
int dp[102][1002];
int rodCutting(int length[],int price[],int l,int n)
{
    for(int i=0;i<n+1;i++)
        for(int j=0;j<l+1;j++)
            if(i==0 || j==0)
                dp[i][j] = 0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<l+1;j++)
        {
            if(length[i-1]<=j)
                dp[i][j] = max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][l];
}
int main()
{
    int n,l;
    cin>>n>>l;
    int length[n];
    int price[n];
    for(int i=0;i<n;i++)
        cin>>length[i]>>price[i];
    cout<<rodCutting(length,price,l,n)<<endl;
    return 0;
}