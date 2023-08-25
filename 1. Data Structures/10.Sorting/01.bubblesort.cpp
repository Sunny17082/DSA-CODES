#include <iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
    int swapped;
    for(int i=0;i<n-1;i++)
    {
        swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swapped=1;
            }
        }
        if(swapped==0)
            break;
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}