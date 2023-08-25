#include <bits/stdc++.h>
using namespace std;
int searchInNearlySortedArray(int arr[],int n,int key)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        else if(mid-1>=start && arr[mid-1]==key)
            return mid-1;
        else if(mid+1<end && arr[mid+1]==key)
            return mid+1;
        else if(arr[mid]>key)
            end=mid-2;
        else
            start=mid+2;
    }
}
int main()
{
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<searchInNearlySortedArray(arr,n,key)<<endl;
    return 0;
}