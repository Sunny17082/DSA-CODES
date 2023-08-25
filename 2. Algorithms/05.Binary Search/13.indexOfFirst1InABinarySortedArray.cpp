#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int start,int end,int key)
{
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
int indexOfFirst1InABinarySortedArray(int arr[])
{
    int start=0,end=1;
    while(1>arr[end])
    {
        start=end;
        end=end*2;
    }
    int index = binarySearch(arr,start,end,1);
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<indexOfFirst1InABinarySortedArray(arr)<<endl;
    return 0;
}