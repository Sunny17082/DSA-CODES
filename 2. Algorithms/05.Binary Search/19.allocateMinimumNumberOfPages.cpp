#include <bits/stdc++.h>
using namespace std;
pair<int,int> maxArraySum(int arr[],int n)
{
    int sum=0;
    int max = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(arr[i]>max)
            max=arr[i];
    }
    return {max,sum};
}
bool isValid(int arr[],int n,int k,int max)
{
    int sum=0,student=1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>max)
        {
            sum=arr[i];
            student++;
        }
        if(student>k)
            return false;
    }
    return true;
}
int allocateMinimumNumberOfPages(int arr[],int n,int k)
{
    if(n<k)
        return -1;
    pair<int,int> maxSum = maxArraySum(arr,n);
    int start = maxSum.first;
    int end = maxSum.second;
    int res=-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(isValid(arr,n,k,mid)==true)
        {
            res=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return res;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<allocateMinimumNumberOfPages(arr,n,k);
    return 0;
}