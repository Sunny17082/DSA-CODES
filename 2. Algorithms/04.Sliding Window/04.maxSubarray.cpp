#include <bits/stdc++.h>
using namespace std;
vector<int> maxSubarray(int arr[],int size,int k)
{
    vector<int> ans;
    deque<int> q; //to store maximum element which is always in front
    int i=0,j=0;
    while(j<size)
    {
        //while the element at j is greater than the previous element
        while(q.size()>0 && q.back()<arr[j])
            q.pop_back();
        q.push_back(arr[j]);
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            ans.push_back(q.front()); //maximum element of a window is always the first element of the queue
            if(q.front()==arr[i]) //if the first element of previous window is maximum
                q.pop_front(); //remove the element from the queue
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
        cin>>arr[i];
    vector<int> v = maxSubarray(arr,n,k);
    for(int i:v)
        cout<<i<<" ";
    return 0;
}