#include <bits/stdc++.h>
using namespace std;
void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}
void sortRatio(float weight[], float profit[], float ratio[], int n)
{
    int swapped = 0;
    for(int i=0;i<n-1;i++)
    {
        swapped = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(ratio[j]<ratio[j+1])
            {
                swap(ratio[j],ratio[j+1]);
                swap(weight[j],weight[j+1]);
                swap(profit[j],profit[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
            break;
    }
}
void knapsack(float weight[], float profit[], float ratio[], int n, float capacity)
{
    int i;
    float x[n]={0}, tprofit = 0;
    for(i=0;i<n;i++)
    {
        if(weight[i]>capacity)
            break;
        else
        {
            x[i] = 1.0;
            tprofit = tprofit+profit[i];
            capacity = capacity-weight[i];
        }
    }
    if(i<n)
    {
        x[i] = capacity/weight[i];
        tprofit = tprofit+(x[i]*profit[i]);
    }
    cout<<"Fraction of each object to be included in the knapsack"<<endl;
    cout<<"weight\tprofit\tfraction"<<endl;
    for(int i=0;i<n;i++)
        cout<<weight[i]<<"\t"<<profit[i]<<"\t"<<x[i]<<endl;
    cout<<"Maximum profit: "<<tprofit<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    float weight[n], profit[n], ratio[n], capacity;
    cout<<"Enter capacity of knapsack: "<<endl;
    cin>>capacity;
    cout<<"Enter the weights and profit of each object: "<<endl;
    for(int i=0;i<n;i++)
        cin>>weight[i]>>profit[i];
    for(int i=0;i<n;i++)
        ratio[i] = profit[i]/weight[i];
    sortRatio(weight, profit, ratio, n);
    knapsack(weight, profit, ratio, n, capacity);
    return 0;
}