#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int h)
{
	int i=l,j=mid+1,k=l;
	int b[h+1];
	while(i<=mid && j<=h)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	for(;i<=mid;i++)
		b[k++]=a[i];
	for(;j<=h;j++)
		b[k++]=a[j];
	for(i=l;i<=h;i++)
		a[i]=b[i];
}
void iMergeSort(int a[],int n)
{
	int p,i,l,h,mid;
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p-1<=n;i=i+p)
		{
			l=i; cout<<"l"<<l<<endl;
			h=i+p-1; cout<<"h"<<h<<endl;
			mid=(l+h)/2; cout<<"mid"<<mid<<endl;
			merge(a,l,mid,h);
		}
	}
	if(p/2<n)
		merge(a,0,p/2-1,n);
}
void rMergeSort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		rMergeSort(a,l,mid);
		rMergeSort(a,mid+1,h);
		merge(a,l,mid,h);
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
	// iMergeSort(a,n);
	rMergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}