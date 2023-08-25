#include <bits/stdc++.h>
using namespace std;
int size=5;
int arr[5];
int front=-1;
int rear=0;
void enqueueFront(int x)
{
    if((front==0 && rear==size-1)||front==rear+1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(front==0)
        front=size-1;
    else
        front--;
    arr[front]=x;
}
void enqueueRear(int x)
{
    if((front==0 && rear==size-1)||front==rear+1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(rear==size-1)
        rear=0;
    else
        rear++;
    arr[rear]=x;
}
void dequeueFront()
{
    if(front==-1)
        cout<<"Queue is empty"<<endl;
    if(front==rear)
        front=rear=-1;
    else if(front==size-1)
        front=0;
    else
        front++;
}
void dequeueRear()
{
    if(front==-1)
        cout<<"Queue is empty"<<endl;
    if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=size-1;
    else
        rear--;
}
void display()
{
    if(front!=-1)
    {
        int i=front;
        do
        {
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        while(i!=(rear+1)%size);
        cout<<"\n";
    }
}
int main()
{
    enqueueRear(10);
    enqueueRear(20);
    enqueueFront(2);
    enqueueRear(30);
    enqueueRear(30);
    dequeueRear();
    dequeueFront();
    enqueueFront(10);
    enqueueRear(20);
    display();
}