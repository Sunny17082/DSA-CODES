#include <bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int n)
{
	int j,x;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		x=a[i];
		while(j>-1 && a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
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
	insertionSort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}