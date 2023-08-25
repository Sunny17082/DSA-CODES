#include <iostream>
using namespace std;
int getbit(int n,int pos)
{
    return ((n&(1<<pos))!=0);
}
int setbit(int n,int pos)
{
	return (n|(1<<pos));
}
int clearbit(int n,int pos)
{
	return (n&(~(1<<pos)));
}
int updatebit(int n,int pos,int value)
{
	n=(n&(~(1<<pos)));
	return (n|(value<<pos));
}
int ispowerof2(int n)
{
	return (n && !(n & (n-1)));
}
int numberof1(int n)
{
	int count=0;
	while(n>0)
	{
		n=(n & n-1);
		count++;
	}
	return count;
}
void subset(int arr[],int n)
{
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if((i & (1<<j)))
				cout<<arr[j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	// cout<<getbit(9,2)<<endl;
	// cout<<setbit(9,1)<<endl;
	// cout<<clearbit(9,3)<<endl;
	// cout<<updatebit(9,0,0)<<endl;
	// cout<<ispowerof2(4)<<endl;
	// cout<<numberof1(5)<<endl;
	int arr[]={1,2,3};
	subset(arr,3);
	return 0;
}