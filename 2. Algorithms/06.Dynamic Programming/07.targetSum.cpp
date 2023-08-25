#include <bits/stdc++.h>
using namespace std;
int countOfSubsetSumWithAGivenSum(int arr[],int n,int sum)
{
    int dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int targetSum(int arr[],int n,int sum)
{
    int arraySum=0;
    for(int i=0;i<n;i++)
        arraySum+=arr[i];
    arraySum=(sum+arraySum)/2;
    return countOfSubsetSumWithAGivenSum(arr,n,arraySum);
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<targetSum(arr,n,sum)<<endl;
    return 0;
}