#include <bits/stdc++.h>
using namespace std;
int firstOccurence(int arr[],int n,int key)
{
    int start=0,end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        {
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    return res;
}
int lastOccurence(int arr[],int n,int key)
{
    int start=0,end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==key)
        {
            res=mid;
            start=mid+1;
        }
        else if(arr[mid]<key)
            start=mid+1;
        else
            end=mid-1;
    }
    return res;
}
int main()
{
    int n,key;
    cin>>n>>key;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"First occurence: "<<firstOccurence(arr,n,key)<<endl;
    cout<<"Last occurence: "<<lastOccurence(arr,n,key)<<endl;
    return 0;
}