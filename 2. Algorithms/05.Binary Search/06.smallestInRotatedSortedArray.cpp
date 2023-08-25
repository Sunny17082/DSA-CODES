#include <bits/stdc++.h>
using namespace std;
int smallestInRotatedSortedArray(int arr[],int n)
{
    //same for finding number of rotation in a sorted rotated array
    int start=0,end=n-1;
    if(n==1)
        return arr[0];
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        //at any instance the smallest element will be both smaller than the previous and next element
        if(arr[mid]<arr[next] && arr[mid]<arr[prev])
            return arr[mid];
        //if the end of the array element is smaller than the mid element then the smaller element will be present in somewhere in between mid+1 and end
        else if(arr[end]<arr[mid])
            start=mid+1;
        //if the end of the array element is greater than the mid element then the smaller element will be present in somewhere in between mid-1 and start
        else
            end=mid-1;
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
    cout<<smallestInRotatedSortedArray(arr,n)<<endl;
    return 0;
}