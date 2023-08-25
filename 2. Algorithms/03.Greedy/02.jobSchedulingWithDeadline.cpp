#include <bits/stdc++.h>
using namespace std;
struct Job
{
    char id;
    int deadline;
    int profit;
};
bool comp(Job a, Job b)
{
    return a.profit>b.profit;
}
void jobScheduling(struct Job arr[], int n)
{
    sort(arr,arr+n,comp);
    int result[n], slot[n] = {0}, tprofit = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i].deadline)-1;j>=0;j--)
        {
            if(slot[j] == 0)
            {
                result[j] = i;
                slot[j] = 1;
                break;
            }
        }
    }
    cout<<"Jobs to be included: "<<endl;
    cout<<"id\tdeadline\tprofit"<<endl;
    for(int i=0;i<n;i++)
    {
        if(slot[i] == 1)
        {
            cout<<arr[result[i]].id<<"\t"<<arr[result[i]].deadline<<"\t\t"<<arr[result[i]].profit<<endl;
            tprofit = tprofit+arr[result[i]].profit;
        }
    }
    cout<<"Maximum profit: "<<tprofit<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of jobs:"<<endl;
    cin>>n;
    struct Job arr[n];
    cout<<"Enter Job id, deadline of job, profit"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
    jobScheduling(arr,n);
    return 0;
}