#include <bits/stdc++.h>
using namespace std;
int coinChangeI(int coin[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=false;
            if(j==0)
                dp[i][j]=true;
        }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
                dp[i][j]=dp[i][j-coin[i-1]]+dp[i-1][j];
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
    cout<<coinChangeI(coin,n,sum)<<endl;
    return 0;
}