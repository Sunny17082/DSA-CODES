#include <bits/stdc++.h>
using namespace std;
int peakElement(int arr[],int n)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(mid>0 && mid<n-1)
        {
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
                return mid;
            else if(arr[mid-1]>arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        else if(mid==0)
            return (arr[0]>arr[1])? 0:1;
        else
            return (arr[n-1]>arr[n-2])? n-1:n-2;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<peakElement(arr,n)<<endl;
    return 0;
}