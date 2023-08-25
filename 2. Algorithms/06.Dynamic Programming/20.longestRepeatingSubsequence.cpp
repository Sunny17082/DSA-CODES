#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];
int longestRepeatingSubsequence(string a,string b,int m,int n)
{
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            if(i==0 || j==0)
                dp[i][j]=0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string a;
    cin>>a;
    int n=a.length();
    cout<<longestRepeatingSubsequence(a,a,n,n)<<endl;
    return 0;
}