#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int start,int end,int key)
{
    if(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            return binarySearch(arr,mid+1,end,key);
        else
            return binarySearch(arr,start,mid-1,key);
    }
    return -1;
}
int searchInAnInfiniteSortedArray(int arr[],int key)
{
    int start=0,end=1;
    while(key>arr[end])
    {
        start=end;
        end=end*2;
    }
    int index = binarySearch(arr,start,end,key);
}
int main()
{
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<searchInAnInfiniteSortedArray(arr,key)<<endl;
    return 0;
}