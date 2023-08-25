#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

/* Recursive */

int recursiveMatrixChainMultiplication(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=recursiveMatrixChainMultiplication(arr,i,k)+recursiveMatrixChainMultiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp);
    }
    return mn;
}

/*Memoized*/

int memoizedMatrixChainMultiplication(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=memoizedMatrixChainMultiplication(arr,i,k)+memoizedMatrixChainMultiplication(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,temp);
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<memoizedMatrixChainMultiplication(arr,1,n-1)<<endl;
    return 0;
}