#include <bits/stdc++.h>
using namespace std;
int maxSumSubarray(int arr[],int size,int k)
{
    int i=0,j=0,sum=0;
    int maxSum = INT_MIN;
    while(j<size) //until j reaches maximum size
    {
        sum+=arr[j]; 
        if(j-i+1<k) //until window size is reached
            j++;
        else if(j-i+1==k) //if window size is reached
        {
            maxSum = max(maxSum,sum);
            sum-=arr[i];//removing first element from each window
            i++;
            j++;
        }
    }
    return maxSum;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxSumSubarray(arr,n,k);
    return 0;
}