#include <bits/stdc++.h>
using namespace std;
int size=5;
int arr[5];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if((rear+1)%size==front)
        cout<<"Queue is full"<<endl;
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=x;
    }
    else
    {
        rear=(rear+1)%size;
        arr[rear]=x;
    }
}
void dequeue()
{
    if(front==-1)
        cout<<"Queue is empty"<<endl;
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
}
void display()
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
int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    enqueue(1);
    dequeue();
    dequeue();
    dequeue();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    return 0;
}