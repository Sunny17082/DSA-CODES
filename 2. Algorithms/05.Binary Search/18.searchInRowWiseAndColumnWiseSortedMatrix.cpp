#include <bits/stdc++.h>
using namespace std;
pair<int,int> searchInRowWiseAndColumnWiseSortedMatrix(int arr[][100],int m,int n,int key)
{
    int i=0,j=n-1;
    while(i>=0 && i<m && j>=0 && j<n)
    {
        if(arr[i][j]==key)
            return {i,j};
        else if(arr[i][j]>key)
            j--;
        else
            i++;
    }
    return {-1,-1};
}
int main()
{
    int m,n,key;
    cin>>m>>n>>key;
    int arr[100][100];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    pair<int,int> index = searchInRowWiseAndColumnWiseSortedMatrix(arr,m,n,key);
    cout<<index.first<<" "<<index.second;
    return 0;
}