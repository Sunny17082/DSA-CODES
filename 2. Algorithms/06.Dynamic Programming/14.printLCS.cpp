#include <bits/stdc++.h>
using namespace std;
int dp[100][1000];
void longestCommonSubsequence(string a,string b,int m,int n)
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
}
string printLCS(string a,string b,int m,int n)
{
    string s="";
    longestCommonSubsequence(a,b,m,n);
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(a[i-1]==b[j-1])
        {
            s=a[i-1]+s;
            i--;
            j--;
        }
        else if(a[i-1]>b[j-1])
            i--;
        else
            j--;
    }
    return s;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int m=a.length();
    int n=b.length();
    cout<<printLCS(a,b,m,n)<<endl;
    return 0;
}