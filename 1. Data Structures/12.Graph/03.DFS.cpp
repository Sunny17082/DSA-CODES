#include <bits/stdc++.h>
using namespace std;
int A[][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
int visited[7]={0,0,0,0,0,0,0};
void DFS(int i)
{
    cout<<i+1<<" ";
    visited[i]=1;
    for(int j=0;j<7;j++)
    {
        if(A[i][j]==1 && visited[j]==0)
            DFS(j);
    }
}
int main()
{
    int i;
    cin>>i;
    DFS(i-1);
    return 0;
}

