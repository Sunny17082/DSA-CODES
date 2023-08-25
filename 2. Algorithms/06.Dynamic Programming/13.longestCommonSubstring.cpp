#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];
int longestCommonSubstring(string a,string b,int m,int n)
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
                dp[i][j]=0;
        }
    }
    int mx=0;
    for(int i=0;i<m+1;i++)
        for(int j=0;j<n+1;j++)
            mx=max(mx,dp[i][j]);
    return mx;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();
    cout<<longestCommonSubstring(a,b,m,n)<<endl;
    return 0;
}