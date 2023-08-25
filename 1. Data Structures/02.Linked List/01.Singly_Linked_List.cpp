#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
}*head,*second,*third;
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
            head->next=NULL;
            temp=head;
        }
        else
        {
            temp->next=new Node();
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void create2()
{
    Node* temp;
    int n,value,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            second=new Node();
            second->data=value;
            second->next=NULL;
            temp=second;
        }
        else
        {
            temp->next=new Node();
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void reverse()
{
    Node* previous=NULL;
    Node* current=head;
    Node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=previous;
        previous=current;
        current=next;
    }
    head=previous;
}
void insertAtFirst(int value)
{
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void insertAtIndex(int value,int index)
{
    Node* newnode = new Node();
    Node* h=head;
    int i=0;
    while(i!=index-1)
    {
        h=h->next;
        i++;
    }
    newnode->data=value;
    newnode->next=h->next;
    h->next=newnode;
}
void insertAtEnd(int value)
{
    Node* newnode=new Node();
    Node* h=head;
    while(h->next!=NULL)
    {
        h=h->next;
    }
    newnode->data=value;
    newnode->next=NULL;
    h->next=newnode;
}
void insertAfterNode(Node* head,Node* previous,int value)
{
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=previous->next;
    previous->next=newnode;
}
void deleteFirst()
{
    Node* h=head;
    head=head->next;
    free(h);
}
void deleteAtIndex(Node* head,int index)
{
    Node* h=head;
    Node* n=head->next;
    int i=0;
    while(i!=index-1)
    {
        h=h->next;
        n=n->next;
        i++;
    }
    h->next=n->next;
    free(n);
}
void deleteLast(Node* head)
{
    Node* h=head;
    Node* n=head->next;
    while(n->next!=NULL)
    {
        h=h->next;
        n=n->next;
    }
    h->next=NULL;
    free(n);
}
void deleteValue(Node* head,int value)
{
    Node* h=head;
    Node* n=head->next;
    while(n->data!=value && n->next!=NULL)
    {
        h=h->next;
        n=n->next;
    }
    if(n->data==value)
    {
        h->next=n->next;
        free(n);
    }
    else
    {
        cout<<"Element not present in the list"<<endl;
    }
}
void search(int value)
{
    Node* h=head;
    while(h->data!=value && h->next!=NULL)
    {
        h=h->next;
    }
    if(h->data==value)
        cout<<"Search successful"<<endl;
    else
        cout<<"Search unsuccessfull"<<endl;
}
void insertSorted(int value)
{
    Node* h=head;
    Node* p=head->next;
    Node* n=new Node();
    while(p && p->data<value)
    {
        p=p->next;
        h=h->next;
    }
    n->data=value;
    if(h==head)
    {
        n->next=head;
        head=n;
    }
    else
    {
        n->next=h->next;
        h->next=n;
    }
}
void isSorted()
{
    Node* h=head;
    int x=h->data;
    int flag=0;
    while(h!=NULL)
    {
        if(x>h->data)
        {
            flag=1;
            break;
        }
        x=h->data;
        h=h->next;
    }
    if(flag==0)
        cout<<"The list is sorted"<<endl;
    else
        cout<<"The list is not sorted"<<endl;
}
void removeDuplicate()
{
    Node* h=head;
    Node* p=head->next;
    while(p!=NULL)
    {
        if(h->data==p->data)
        {
            h->next=p->next;
            free(p);
            p=h->next;
        }
        else
        {
            h=h->next;
            p=p->next;
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
void display1(Node* head)
{
    if(head!=NULL)
    {
        cout<<head->data<<" ";

        display1(head->next);
    }
}
void concatenate(Node* p,Node* q)
{
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
}
void merge(Node* p,Node* q)
{
    Node* last=NULL;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p!=NULL)
        last->next=p;
    if(q!=NULL)
        last->next=q;
}
void isLoop(Node* head)
{
    Node* p=head;
    Node* q=head;
    do
    {
        p=p->next;
        q=q->next;
        if(q!=NULL)
            q=q->next;
    }
    while(p!=NULL && q!=NULL && p!=q);
    if(p==q)
        cout<<"Loop"<<endl;
    else
        cout<<"Linear"<<endl;
}
int main ()
{
    create();
    create2();
    display(head);
    cout<<"\n";
    // reverse();
    // insertAtFirst(2);
    // insertAtIndex(5,1);
    // insertAtEnd(6);
    // insertAfterNode(head,head,0);
    // deleteFirst();
    // deleteAtIndex(head,2);
    // deleteLast(head);
    // deleteValue(head,3);
    // display(head);
    // display1(head);
    // search(0);
    // insertSorted(0);
    // isSorted();
    // removeDuplicate();
    // concatenate(head,second);
    // merge(head,second);
    // display(third);
    Node* t1;
    Node* t2;
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    isLoop(t2);
    return 0;
}