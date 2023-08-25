#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
void insertSorted(Node **h,int x)
{
    Node* q=NULL,*p=*h;
    Node* t=new Node();
    t->data=x;
    t->next=NULL;
    if(*h==NULL)
        *h=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==*h)
        {
            t->next=*h;
            *h=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
Node* search(Node *p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}
int Hash(int key)
{
    return key%10;
}
void insert(Node* h[],int key)
{
    int index=Hash(key);
    insertSorted(&h[index],key);
}
int main()
{
    Node* HT[10];
    int n,key,x;
    cin>>n>>key;
    for(int i=0;i<10;i++)
        HT[i]=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        insert(HT,x);
    }
    Node* temp=search(HT[Hash(key)],key);
    if(temp!=NULL)
        cout<<"Element found at address : "<<temp<<endl;
    else
        cout<<"Element not found"<<endl;
    return 0;
}