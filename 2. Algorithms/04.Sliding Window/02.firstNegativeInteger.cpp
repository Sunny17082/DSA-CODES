#include <bits/stdc++.h>
using namespace std;
vector<int> firstNegativeInteger(int arr[],int size,int k)
{
    int i=0,j=0;
    queue<int> q; //to store negative elements
    vector<int> ans;
    while(j<size)
    {
        if(arr[j]<0)
            q.push(arr[j]);
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            if(q.size()==0) //if no negative number in a window
                ans.push_back(0);
            else
            {
                ans.push_back(q.front()); //push first negative number from the queue
                if(arr[i]<0) //if the first element of the window is negative
                    q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v = firstNegativeInteger(arr,n,k);
    for(int i:v)
        cout<<i<<" ";
    return 0;
}