#include <bits/stdc++.h>
using namespace std;
char nextLetter(string s,int n,char key)
{
    int start=0,end=n-1;
    char res=' ';
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(s[mid]==key)
            start=mid+1;
        else if(s[mid]>key)
        {
            res=s[mid];
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return res;
}
int main()
{
    int n;
    char key;
    cin>>n>>key;
    string s;
    cin>>s;
    cout<<nextLetter(s,n,key)<<endl;
    return 0;
}