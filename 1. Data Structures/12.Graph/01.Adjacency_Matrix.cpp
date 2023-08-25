#include <bits/stdc++.h>
#define MAX 100
using namespace std;
//Undirected Graph
void insert_edge_U(int adj[][MAX],int i,int j)
{
    adj[i][j]=adj[j][i]=1;
}
void delete_edge_U(int adj[][MAX],int i,int j)
{
    adj[i][j]=adj[j][i]=0;
}
//Directed Graph
void insert_edge_D(int adj[][MAX],int i,int j)
{
    adj[i][j]=1;
}
void delete_edge_D(int adj[][MAX],int i,int j)
{
    adj[i][j]=0;
}
//Weighted Undirected Graph
void insert_edge_W_U(int adj[][MAX],int i,int j,int weight)
{
    adj[i][j]=adj[j][i]=weight;
}
//Weighted Directed Graph
void insert_edge_W_D(int adj[][MAX],int i,int j,int weight)
{
    adj[i][j]=weight;
}
void printAdjMatrix(int adj[][MAX],int vertex)
{
    for(int i=0;i<=vertex;i++)
    {
        for(int j=0;j<=vertex;j++)
        {
            if(j==0)
                cout<<"{";
            cout<<adj[i][j];
            if(j!=vertex)
                cout<<",";
            else
            {
                cout<<"}";
                if(i!=vertex)
                    cout<<",";
            }
        }
        cout<<endl;
    }
}
int main()
{
    int adj[MAX][MAX];
    int vertex,edge,weight,origin,destin;
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        cin>>origin>>destin;
        cin>>weight;
        insert_edge_W_U(adj,origin,destin,weight);
    }
    printAdjMatrix(adj,vertex);
    return 0;
}