#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* prev;
    Node* next;
}*head;
void create()
{
    int n,value;
    cin>>n;
    Node* temp;
    Node* newnode;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=new Node();
            head->data=value;
            head->prev=NULL;
            head->next=NULL;
            temp=head;
        }
        else
        {
            newnode=new Node();
            newnode->data=value;
            newnode->prev=temp;
            newnode->next=NULL;
            temp->next=newnode;
            temp=newnode;
        }
    }
}
void display(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    create();
    display(head);
    return 0;
}