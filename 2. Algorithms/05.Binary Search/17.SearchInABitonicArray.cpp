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
int binarySearch(int arr[],int start,int end,int key)
{
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
int reverseBinarySearch(int arr[],int start,int end,int key)
{
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
    int index = peakElement(arr,n);
    int left = binarySearch(arr,0,index,key);
    int right = reverseBinarySearch(arr,index+1,n-1,key);
    if(left==-1 && right==-1)
         cout<<-1<<endl;
    (left!=-1)? cout<<left<<endl:cout<<right<<endl;
    return 0;
}