#include <bits/stdc++.h>
using namespace std;
int dp[102][1002];

/* Recursive */

int recursiveUnboundedKnapsack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
        return 0;
    if(wt[n-1]<=w)
        return max(val[n-1]+recursiveUnboundedKnapsack(wt,val,w-wt[n-1],n),recursiveUnboundedKnapsack(wt,val,w,n-1));
    else if(wt[n-1]>w)
        return recursiveUnboundedKnapsack(wt,val,w,n-1);
}

/* Memoized */

int memoizedUnboundedKnapsack(int wt[],int val[],int w,int n)
{
    memset(dp,-1,sizeof(dp));
    if(n==0 || w==0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    if(wt[n-1]<=w)
        return dp[n][w] = max(val[n-1]+memoizedUnboundedKnapsack(wt,val,w-wt[n-1],n),memoizedUnboundedKnapsack(wt,val,w,n-1));
    else if(wt[n-1]>w)
        return dp[n][w] = memoizedUnboundedKnapsack(wt,val,w,n-1);
}

/* Bottom-up */

int unboundedKnapsack(int wt[],int val[],int w,int n)
{
    for(int i=0;i<n+1;i++)
        for(int j=0;j<w+1;j++)
            if(i==0 || j==0)
                dp[i][j] = 0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    int n,w;
    cin>>n>>w;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    cout<<unboundedKnapsack(wt,val,w,n)<<endl;
    return 0;
}