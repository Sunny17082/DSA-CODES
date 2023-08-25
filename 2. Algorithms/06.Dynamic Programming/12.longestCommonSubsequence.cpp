#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];

/* Recursive */

int recursiveLongestCommonSubsequence(string a,string b,int m,int n)
{
    if(m==0||n==0)
        return 0;
    if(a[m-1]==b[n-1])
        return 1+recursiveLongestCommonSubsequence(a,b,m-1,n-1);
    else
        return max(recursiveLongestCommonSubsequence(a,b,m-1,n),recursiveLongestCommonSubsequence(a,b,m,n-1));
}

/* Memoized */

int memoizedLongestCommonSubsequence(string a,string b,int m,int n)
{
    memset(dp,-1,sizeof(dp));
    if(m==0||n==0)
        return 0;
    if(dp[m][n]!=-1)
        return dp[m][n];
    if(a[m-1]==b[n-1])
        return dp[m][n] = 1+memoizedLongestCommonSubsequence(a,b,m-1,n-1);
    else
        return dp[m][n] = max(memoizedLongestCommonSubsequence(a,b,m-1,n),memoizedLongestCommonSubsequence(a,b,m,n-1));
}

/* Bottom-up */

int longestCommonSubsequence(string a,string b,int m,int n)
{
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();
    cout<<longestCommonSubsequence(a,b,m,n)<<endl;
    return 0;
}