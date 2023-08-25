#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int n,int key)
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
int reverseBinarySearch(int arr[],int n,int key)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            end=mid-1;
        else
            start=mid+1;
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
    if(arr[0]<arr[n-1])
        cout<<binarySearch(arr,n,key)<<endl; //if array is sorted in increasing order
    else
        cout<<reverseBinarySearch(arr,n,key)<<endl; //if array is sorted in decreasing order
    return 0;
}