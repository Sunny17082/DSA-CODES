#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
    Node* t=new Node();
    if(t==NULL)
        cout<<"Queue is full"<<endl;
    else
    {
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}
void dequeue()
{
    Node* t;
    if(front==NULL)
        cout<<"Queue is empty"<<endl;
    else
    {
        t=front;
        front=front->next;
        free(t);
    }
}
void display()
{
    Node* p=front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    printf("\n");
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}