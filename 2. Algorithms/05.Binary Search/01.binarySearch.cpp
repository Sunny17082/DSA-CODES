#include <bits/stdc++.h>
using namespace std;
int iBinarySearch(int arr[],int n,int key)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    return -1;
}
int rBinarySearch(int arr[],int start,int end,int key)
{
    if(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return rBinarySearch(arr,mid+1,end,key);
        else
            return rBinarySearch(arr,start,mid-1,key);
    }
    return -1;
}
int main()
{
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    // cout<<iBinarySearch(arr,n,key)<<endl;
    cout<<rBinarySearch(arr,0,n,key)<<endl;
    return 0;
}