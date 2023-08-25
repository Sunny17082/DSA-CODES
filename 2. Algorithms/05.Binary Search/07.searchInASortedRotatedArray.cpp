#include <bits/stdc++.h>
using namespace std;

/*Approach 1*/

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
            return mid;
        //if the end of the array element is smaller than the mid element then the smaller element will be present in somewhere in between mid+1 and end
        else if(arr[end]<arr[mid])
            start=mid+1;
        //if the end of the array element is greater than the mid element then the smaller element will be present in somewhere in between mid-1 and start
        else
            end=mid-1;
    }
    return -1;
}
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

/*Approach 2*/

int search(int arr[],int n,int key)
{
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[start]<arr[mid])
        {
            if(key>=arr[start] && key<=arr[mid])
                end=mid-1;
            else
                start=mid+1;
        }
        else
        {
            if(key>=arr[mid] && key<=arr[end])
                start=mid+1;
            else
                end=mid-1;
        }
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
    // int index = smallestInRotatedSortedArray(arr,n);
    // by finding the smallest element's index we are dividing the array into two sorted array
    // int left = binarySearch(arr,0,index-1,key);
    // int right = binarySearch(arr,index,n-1,key);
    // if(left==-1 && right==-1)
    //     cout<<-1<<endl;
    // else if(left!=-1)
    //     cout<<left<<endl;
    // else
    //     cout<<right<<endl;
    cout<<search(arr,n,key);
    return 0;
}