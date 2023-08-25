#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int priority;
    int data;
    Node* next;
}*front=NULL;
void enqueue(int priority,int data)
{
    Node* t=new Node();
    Node* h=front;
    if(t==NULL)
        cout<<"Queue is Full"<<endl;
    else
    {
        t->priority=priority;
        t->data=data;
        if(front==NULL || priority<front->priority)
        {
            t->next=front;
            front=t;
        }
        else
        {
            while(h->next!=NULL && h->next->priority<=priority)
                h=h->next;
            t->next=h->next;
            h->next=t;
        }
    }
}
void dequeue()
{
    Node* p=front;
    front=front->next;
    free(p);
}
void display(Node* front)
{
    while(front!=NULL)
    {
        cout<<front->data<<" ";
        front=front->next;
    }
    cout<<"\n";
}
int main()
{
    enqueue(1,5);
    enqueue(1,6);
    enqueue(2,8);
    enqueue(3,8);
    enqueue(2,7);
    dequeue();
    display(front);
    return 0;
}