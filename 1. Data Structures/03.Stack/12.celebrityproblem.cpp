#include <bits/stdc++.h>
using namespace std;
int celebrity(int m[][4],int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
        s.push(i);
    while(s.size()>1)
    {
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        if(m[a][b]==1)
            s.push(b);
        else
            s.push(a);
    }
    int c=s.top();
    s.pop();
    for(int i=0;i<n;i++)
    {
        if((i!=c)&&(m[c][i]==1||m[i][c]==0))
            return-1;
    }
    return c;
}
int main()
{
    int n=4;
    int m[4][4]={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
    cout<<celebrity(m,n)<<endl;
    return 0;
}