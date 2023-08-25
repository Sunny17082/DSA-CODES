#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
bool isPalindrome(string s,int i,int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

/* Recursive */

int recursivePalindromePartitioning(string s,int i,int j)
{
    if(i>=j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=recursivePalindromePartitioning(s,i,k)+recursivePalindromePartitioning(s,k+1,j)+1;
        mn=min(mn,temp);
    }
    return mn;
}

/* Memoized */

int memoizedPalindromePartitioning(string s,int i,int j)
{
    if(i>=j)
        return 0;
    if(isPalindrome(s,i,j))
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        // int temp=memoizedPalindromePartitioning(s,i,k)+memoizedPalindromePartitioning(s,k+1,j)+1;
        int left,right;
        if(dp[i][k]!=-1)
            left=dp[i][k];
        else
        {
            left=memoizedPalindromePartitioning(s,i,k);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1)
            right=dp[k+1][j];
        else
        {
            right=memoizedPalindromePartitioning(s,k+1,j);
            dp[k+1][j]=right;
        }
        int temp=left+right+1;
        mn=min(mn,temp);
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s;
    cin>>s;
    cout<<memoizedPalindromePartitioning(s,0,s.length()-1)<<endl;
    return 0;
}