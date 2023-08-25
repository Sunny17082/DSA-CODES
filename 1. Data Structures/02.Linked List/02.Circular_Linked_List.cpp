#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
}*head;
void create()
{
    Node* temp;
    int n,value,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=new Node();
            head->data=value;
            head->next=head;
            temp=head;
        }
        else
        {
            temp->next=new Node();
            temp=temp->next;
            temp->data=value;
            temp->next=head;
        }
    }
}
void inseratFirst(int value)
{
    Node* n=new Node();
    n->data=value;
    Node* h=head;
    while(h->next!=head)
    {
        h=h->next;
    }
    n->next=head;
    head=n;
    h->next=n;
}
void insertatIndex(int value,int index)
{
    Node* n=new Node();
    n->data=value;
    Node* h=head;
    int i=0;
    while(i!=index-1)
    {
        h=h->next;
        i++;
    }
    n->next=h->next;
    h->next=n;
}
void insertAtEnd(int value)
{
    Node* n=new Node();
    n->data=value;
    Node* h=head;
    do
    {
        h=h->next;
    }
    while(h->next!=head);
    n->next=head;
    h->next=n;
}
void deleteFirst()
{
    Node* h=head;
    Node* p=head->next;
    while(p->next!=h)
    {
        p=p->next;
    }
    head=h->next;
    p->next=head;
    free(h);
}
void deleteIndex(int index)
{
    Node* h=head;
    Node* p=head->next;
    int i=0;
    while(i!=index-1)
    {
        h=h->next;
        p=p->next;
        i++;
    }
    h->next=p->next;
    free(p);
}
void deleteLast()
{
    Node* h=head;
    Node* p=head->next;
    while(p->next!=head)
    {
        h=h->next;
        p=p->next;
    }
    h->next=head;
    free(p);
}
void display(Node* head)
{
    Node* h=head;
    do
    {
        cout<<h->data<<" ";
        h=h->next;
    }
    while(h!=head);
}
int main()
{
    create();
    display(head);
    // inseratFirst(0);
    // insertatIndex(0,2);
    // insertAtEnd(0);
    // deleteFirst();
    // deleteIndex(4);
    deleteLast();
    cout<<"\n";
    display(head);
    return 0;
}
