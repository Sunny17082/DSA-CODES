#include <bits/stdc++.h>
using namespace std;
bool dp[100][1000];
void subsetSum(int arr[],int n,int sum)
{
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
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
}
int minimumSubsetSumDifference(int arr[],int n)
{
    int mn=INT_MAX,sum=0;
    vector<int> v;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    subsetSum(arr,n,sum);
    for(int i=0;i<=sum/2;i++)
        if(dp[n][i]==1)
            v.push_back(i);
    for(int i=0;i<v.size();i++)
        mn=min(mn,(sum-2*v[i]));
    return mn;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<minimumSubsetSumDifference(arr,n)<<endl;
    return 0;
}