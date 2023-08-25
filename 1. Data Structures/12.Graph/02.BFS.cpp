#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int node,i;
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
    cin>>i;
    cout<<i<<" ";
    visited[i-1]=1;
    q.push(i-1);
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        for(int j=0;j<7;j++)
        {
            if(A[node][j]==1 && visited[j]==0)
            {
                cout<<j+1<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }
    return 0; 
}