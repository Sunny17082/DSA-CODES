#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];

/* Recursive */

int recursiveEggDroppingProblem(int e,int f)
{
    if(f==0||f==1)
        return f;
    if(e==1)
        return f;
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(recursiveEggDroppingProblem(e-1,k-1),recursiveEggDroppingProblem(e,f-k));
        mn=min(mn,temp);
    }
    return mn;
}

/* Memoized */

int memoizedEggDroppingProblem(int e,int f)
{
    if(f==0||f==1)
        return f;
    if(e==1)
        return f;
    if(dp[e][f]!=-1)
        return dp[e][f];
    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        // int temp=1+max(memoizedEggDroppingProblem(e-1,k-1),memoizedEggDroppingProblem(e,f-k));
        int low,high;
        if(dp[e-1][k-1]!=-1)
            low=dp[e-1][k-1];
        else
        {
            low=memoizedEggDroppingProblem(e-1,k-1);
            dp[e-1][k-1]=low;
        }
        if(dp[e][f-k]!=-1)
            high=dp[e][f-k];
        else
        {
            high=memoizedEggDroppingProblem(e,f-k);
            dp[e][f-k]=high;
        }
        int temp=1+max(high,low);
        mn=min(mn,temp);
    }
    return dp[e][f]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int e,f;
    cin>>e>>f;
    cout<<memoizedEggDroppingProblem(e,f)<<endl;
    return 0;
}