#include <bits/stdc++.h>
using namespace std;
int v = 9;
int minDistance(int distance[], int included[])
{
    int min = INT_MAX, index;
    for(int i=0;i<v;i++)
        if(included[i] == 0 && distance[i]<=min)
        {
            min = distance[i];
            index = i;
        }
    return index;
}
void printSolution(int distance[])
{
    cout<<"vertex\tDistance from source"<<endl;
    for(int i=0;i<v;i++)
        cout<<i<<"\t"<<distance[i]<<endl;
}
void dijkstra(int graph[][9], int source)
{
    int distance[v], included[v]={0};
    for(int i=0;i<v;i++)
        distance[i] = INT_MAX;
    distance[source] = 0;
    for(int i=0;i<v-1;i++)
    {
        int u = minDistance(distance, included);
        included[u] = 1;
        for(int j=0;j<v;j++)
            if(!included[j] && graph[u][j] && distance[u] != INT_MAX && distance[u]+graph[u][j]<distance[j])
                distance[j] = distance[u]+graph[u][j];
    }
    printSolution(distance);
}
int main()
{
    int graph[9][9] = { {0,4,0,0,8,0,0,0,0},
                        {4,0,8,0,11,0,0,0,0},
                        {0,8,0,7,0,0,14,0,2},
                        {0,0,7,0,0,0,14,9,0},
                        {8,11,0,0,0,1,0,0,7},
                        {0,0,0,0,1,0,2,0,6},
                        {0,0,14,14,0,2,0,10,0},
                        {0,0,0,9,0,0,10,0,0},
                        {0,0,2,0,7,6,0,0,0} };
    dijkstra(graph,0);
    return 0;
}