#include <bits/stdc++.h>
using namespace std;
struct Activity
{
    int start,finish;
};
bool compare(Activity a, Activity b)
{
    return a.finish<b.finish;
}
void activitySelection(Activity arr[], int n)
{
    sort(arr,arr+n,compare);
    int i=0;
    cout<<"activities selected"<<endl;
    cout<<"start\tfinish"<<endl;
    cout<<arr[i].start<<"\t"<<arr[i].finish<<endl;
    for(int j=1;j<n;j++)
    {
        if(arr[j].start>=arr[i].finish)
        {
            cout<<arr[j].start<<"\t"<<arr[j].finish<<endl;
            i = j;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of activities: "<<endl;
    cin>>n;
    struct Activity arr[n];
    cout<<"Enter start and finish time: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish;
    activitySelection(arr,n);
    return 0;
}