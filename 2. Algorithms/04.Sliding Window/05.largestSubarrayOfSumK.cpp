#include <bits/stdc++.h>
using namespace std;
int largestSubarrayOfSumK(int arr[],int size,int k)
{
    int i=0,j=0,sum=0;
    int maxSize = INT_MIN;
    while(j<size)
    {
        sum+=arr[j];
        if(sum<k) //adding until it reaches maximum sum
            j++;
        else if(sum==k) //if sum is reached
        {
            maxSize=max(maxSize,j-i+1); //find max among sum of each subarray
            j++;
        }
        else if(sum>k) //if sum exceeds maximum limit
        {
            while(sum>k) //until sum goes below maximum limit
            {
                sum-=arr[i]; //delete from starting index
                i++;
            }
            j++;
        }
    }
    return maxSize;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<largestSubarrayOfSumK(arr,n,k)<<endl;
    return 0;
}