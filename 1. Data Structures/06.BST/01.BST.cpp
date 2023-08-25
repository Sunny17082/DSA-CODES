#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
}*root=NULL;
void insert(int x)
{
    Node* r,* p;
    Node* t=root;
    if(root==NULL)
    {
        root=new Node();
        root->data=x;
        root->left=root->right=NULL;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(x<t->data)
            t=t->left;
        else if(x>t->data)
            t=t->right;
        else
            return;
    }
    p = new Node();
    p->data=x;
    p->left=p->right=NULL;
    if(x<r->data)
        r->left=p;
    else
        r->right=p;
}
void inorder(Node* p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
Node* search(int key)
{
    Node* t=root;
    while(t!=NULL)
    {
        if(key<t->data)
            t=t->left;
        else if(key>t->data)
            t=t->right;
        else
            return t;
    }
    return NULL;
}
Node* recSearch(Node* p, int key)
{
    if(key<p->data)
        recSearch(p->left,key);
    else if(key>p->data)
        recSearch(p->right,key);
    else if(key==p->data)
        return p;
    else
        return NULL;
}
Node* recInsert(Node *p, int x)
{
    Node *t = NULL;
    if(p==NULL)
    {
        t = new Node();
        t->data=x;
        t->left=t->right=NULL;
        return t;
    }
    if(x<p->data)
        p->left = recInsert(p->left,x);
    else if(x>p->data)
        p->right = recInsert(p->right,x);
    return p;
}
int Height(Node* p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->left);
    y=Height(p->right);
    if(x>y)
        return x+1;
    else
        return y+1;
}
Node* InPre(Node* p)
{
    while(p && p->right!=NULL)
        p=p->right;
    return p;
}
Node* InSuc(Node* p)
{
    while(p && p->left!=NULL)
        p=p->left;
    return p;
}
Node* Delete(Node* p,int x)
{
    Node* q;
    if(p==NULL)
        return NULL;
    if(p->left==NULL && p->right==NULL)
    {
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    if(x<p->data)
        p->left=Delete(p->left,x);
    else if(x>p->data)
        p->right=Delete(p->right,x);
    else
    {
        if(Height(p->left)>Height(p->right))
        {
            q=InPre(p->left);
            p->data=q->data;
            p->left=Delete(p->left,q->data);
        }
        else
        {
            q=InSuc(p->right);
            p->data=q->data;
            p->right=Delete(p->right,q->data);
        }
    }
}
void CreatePre(int *pre,int n)
{
    int i=0;
    root=new Node();
    root->data=pre[i++]
    root->left=root->right=NULL;
    Node* t;
    Node* p=root;
    stack<Node*> s;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new Node();
            t->data=pre[i++];
            t->left=t->right=NULL;
            p->left=t;
            s.push(p);
        }
        else
        {
            if(pre[i]>p->data && pre[i]<s.empty()?32767:s.top()->data)
            {
                t=new Node();
                t->data=pre[i++];
                t->left=t->right=NULL;
                p->right=t;
                p-t;
            }
            else
            {
                p=s.top();
                s.pop();
            }
        }       
    }
}
int main()
{
    int n,value;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        insert(value);
    }
    inorder(root);
    cout<<endl;
    Delete(root,5);
    inorder(root);
    cout<<endl;
    // cout<<recSearch(root,4)<<endl;
    return 0;
}
