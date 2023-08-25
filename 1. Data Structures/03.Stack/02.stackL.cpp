#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
}*top;
int isEmpty()
{
	if (top==NULL)
		return 1;
	else
		return 0;
}
int isFull()
{
	Node* p=new Node();
	if (p==NULL)
		return 1;
	else
		return 0;
}
void push(int x)
{
	Node* n=new Node();
	if (n==NULL)
		cout<<"Stack Overflow"<<endl;
	else
	{
		n->data=x;
		n->next=top;
		top=n;
	}
}
void display(Node* top)
{
	while(top!=NULL)
	{
		cout<<top->data<<" ";
		top=top->next;
	}
}
void pop()
{
	if (top==NULL)
		cout<<"Stack Underflow"<<endl;
	else
	{
		Node* n=top;
		top=top->next;
		cout<<n->data<<" ";
		free(n);
	}
}
int peek(int index)
{
	Node* p=top;
	int i=0;
	while(i!=index-1 && p!=NULL)
	{
		i++;
		p=p->next;
	}
	if (p!=NULL)
		return p->data;
	else
		return -1;
}
int main()
{
	push(5);
	push(10);
	push(15);
	display(top);
	cout<<"\n";
	pop();
	cout<<"\n";
	cout<<peek(1)<<endl;
	return 0;
}