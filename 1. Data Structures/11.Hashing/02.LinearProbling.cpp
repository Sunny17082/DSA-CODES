#include <bits/stdc++.h>
#define size 10
using namespace std;
int Hash(int key)
{
    return key%10;
}
int probe(int H[],int key)
{
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%size]!=0)
        i++;
    return (index+i)%size;
}
void insert(int H[],int key)
{
    int index=Hash(key);
    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
}
int search(int H[],int key)
{
    int index=Hash(key);
    int i=0;
    while(H[(index+i)%size]!=key && H[(index+i)%size]!=0)
        i++;
    if(H[(index+i)%size]==0)
        return -1;
    return (index+i)%size;
}
int main()
{
    int n,key,x;
    int HT[10]={0};
    cin>>n>>key;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(HT,x);
    }
    int t=search(HT,key);
    if(t!=-1)
        cout<<"Element found at index "<<t<<endl;
    else
        cout<<"Element not found "<<endl;
    return 0;
}









































