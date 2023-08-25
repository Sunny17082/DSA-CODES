#include <bits/stdc++.h>
using namespace std;
#define I INT_MAX-1;
int coinChangeII(int coin[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=I;
            if(j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(j%coin[0]==0)
                dp[i][j]=j/coin[0];
            else
                dp[i][j]=I;
        }
    }
    for(int i=2;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
                dp[i][j]=min(dp[i][j-coin[i-1]]+1,dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int coin[n];
    for(int i=0;i<n;i++)
        cin>>coin[i];
    cout<<coinChangeII(coin,n,sum)<<endl;
    return 0;
}