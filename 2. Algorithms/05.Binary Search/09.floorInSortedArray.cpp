#include <bits/stdc++.h>
using namespace std;
int floorInSortedArray(int arr[],int n,int key)
{
    int start=0,end=n-1;
    int res=-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return arr[mid];
        else if(arr[mid]>key)
            end=mid-1;
        else
        {
            res=arr[mid];
            start=mid+1;
        }
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
    cout<<floorInSortedArray(arr,n,key)<<endl;
    return 0;
}