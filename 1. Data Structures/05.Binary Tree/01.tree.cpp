#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
}*root=NULL;
void createTree()
{
    Node* p,* t;
    int x;
    queue<Node* > q;
    cout<<"Enter root value"<<endl;
    cin>>x;
    root=new Node();
    root->data=x;
    root->left=root->right=NULL;
    q.push(root);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cout<<"Enter left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            q.push(t);
        }
        cout<<"Enter right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node();
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            q.push(t);
        }
    }
}
Node* create()
{
    Node* newnode=new Node();
    int x;
    cin>>x;
    if(x==-1)
        return 0;
    newnode->data=x;
    cout<<"Enter left child of "<<x<<endl;
    newnode->left=create();
    cout<<"Enter right child of "<<x<<endl;
    newnode->right=create();
    return newnode;
}
void preorder(Node* p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(Node* p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
void postorder(Node* p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
    }
}
void pre(Node* t)
{
    stack <Node*> s;
    while(t!=NULL || !s.empty())
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            s.push(t);
            t=t->left;
        }
        else
        {
            t=s.top();
            s.pop();
            t=t->right;
        }
    }
}
void in(Node* t)
{
    stack <Node*> s;
    while(t!=NULL || !s.empty())
    {
        if(t!=NULL)
        {
            s.push(t);
            t=t->left;
        }
        else
        {
            t=s.top();
            s.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }
}
void post(Node* t)
{
    stack <long int> s;
    long int temp;
    while(t!=NULL || !s.empty())
    {
        if(t!=NULL)
        {
            s.push((long int)t);
            t=t->left;
        }
        else
        {
            temp=s.top();
            s.pop();
            if(temp>0)
            {
                s.push(-temp);
                t=((Node*)temp)->right;
            }
            else
            {
                cout<<((Node*)(-1*temp))->data<<" ";
                t=NULL;
            }
        }
    }
}
void levelorder(Node* p)
{
    queue<Node*> q;
    cout<<p->data<<" ";
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->left!=NULL)
        {
            cout<<p->left->data<<" ";
            q.push(p->left);
        }
        if(p->right!=NULL)
        {
            cout<<p->right->data<<" ";
            q.push(p->right);
        }
    }
}
int count(Node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count(p->left);
        y=count(p->right);
        return x+y+1;
    }
    return 0;
}
int count2deg(Node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count2deg(p->left);
        y=count2deg(p->right);
        if(p->left!=NULL && p->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int sum(Node* p)
{   
    int x,y;
    if(p!=NULL)
    {
        x=sum(p->left);
        y=sum(p->right);
            return x+y+p->data;
    }
    return 0;
}
int height(Node* p)
{   
    int x=0,y=0;
    if(p!=NULL)
    {
        x=height(p->left);
        y=height(p->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}
int countleaf(Node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=countleaf(p->left);
        y=countleaf(p->right);
        if(p->left==NULL && p->right==NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int count1or2deg(Node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count1or2deg(p->left);
        y=count1or2deg(p->right);
        if(p->left!=NULL || p->right!=NULL)
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int count1deg(Node* p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count1deg(p->left);
        y=count1deg(p->right);
        if((p->left==NULL && p->right!=NULL)||(p->left!=NULL && p->right==NULL))
            return x+y+1;
        else
            return x+y;
    }
    return 0;
}
int main()
{
    // cout<<"Enter root"<<endl;
    // Node* root=create();
    // preorder(root);
    createTree();
    pre(root);
    cout<<endl;
    in(root);
    cout<<endl;
    post(root);
    cout<<endl;
    levelorder(root);
    cout<<endl;
    cout<<count(root)<<endl;
    cout<<count2deg(root)<<endl;
    cout<<sum(root)<<endl;
    cout<<height(root)<<endl;
    cout<<countleaf(root)<<endl;
    cout<<count1or2deg(root)<<endl;
    cout<<count1deg(root)<<endl;
    return 0;
}

