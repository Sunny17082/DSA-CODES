#include <bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int h)
{
	int pivot=a[h];
	int i=l-1;
	for(int j=l;j<=h;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[h]);
	return i+1;
}
void quickSort(int a[],int l,int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}