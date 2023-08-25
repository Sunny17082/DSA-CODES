#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;

/* Recursive */

bool recursiveScrambleString(string a,string b)
{
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;
    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++)
    {
        if((recursiveScrambleString(a.substr(0,i),b.substr(n-i,i))==true && recursiveScrambleString(a.substr(i,n-i),b.substr(0,n-i))==true) || (recursiveScrambleString(a.substr(0,i),b.substr(0,i))==true && recursiveScrambleString(a.substr(i,n-i),b.substr(i,n-i))==true))
        {
            flag=true;
            break;
        }
    }
    return flag;
}

/* Memoized */

bool memoizedScrambleString(string a,string b)
{
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;
    string key = a+" "+b;
    if(mp.find(key)!=mp.end())
        return mp[key];
    int n=a.length();
    bool flag=false;
    for(int i=1;i<=n-1;i++)
    {
        if((memoizedScrambleString(a.substr(0,i),b.substr(n-i,i))==true && memoizedScrambleString(a.substr(i,n-i),b.substr(0,n-i))==true) || (memoizedScrambleString(a.substr(0,i),b.substr(0,i))==true && memoizedScrambleString(a.substr(i,n-i),b.substr(i,n-i))==true))
        {
            flag=true;
            break;
        }
    }
    return mp[key]=flag;
}
int main()
{
    string a,b;
    cin>>a>>b;
    // if(a.length()!=b.length())
    //     return false;
    // if(a.length()==0 && b.length()==0)
    //     return true;
    cout<<memoizedScrambleString(a,b)<<endl;
    return 0;
}