#include <bits/stdc++.h>
using namespace std;
int size=10;
int arr[10];
int front=-1;
int rear=-1;
int enqueue(int x)
{
    if(rear==size-1)
        cout<<"Queue is full"<<endl;
    else
    {
        rear++;
        arr[rear]=x;
    }
}
void dequeue()
{
    if(front==rear)
        cout<<"Queue is empty"<<endl;
    else
    {
        front++;
        arr[front];
    }
}
void display()
{
    for(int i=front+1;i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
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