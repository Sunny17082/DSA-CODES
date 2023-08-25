#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> mp;

/* Recursive */

int recursiveEvaluateExpressionToTrue(string s,int i,int j,bool isTrue)
{
    if(i>j)
        return false;
    if(i==j)
    {
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=recursiveEvaluateExpressionToTrue(s,i,k-1,true);
        int lf=recursiveEvaluateExpressionToTrue(s,i,k-1,false);
        int rt=recursiveEvaluateExpressionToTrue(s,k+1,j,true);
        int rf=recursiveEvaluateExpressionToTrue(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue==true)
                ans+=lt*rt;
            else
                ans+=lf*rt+lf*rf+lf*rf;
        }
        else if(s[k]=='|')
        {
            if(isTrue==true)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^')
        {
            if(isTrue==true)
                ans+=lf*rt+lt*rf;
            else
                ans+=lt*rt+lf*rf;
        }
    }
    return ans;
}

/* Memoized */

int memoizedEvaluateExpressionToTrue(string s,int i,int j,bool isTrue)
{
    if(i>j)
        return false;
    if(i==j)
    {
        if(isTrue==true)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans=0;
    string temp = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");
    if(mp.find(temp)!=mp.end())
        return mp[temp];
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=memoizedEvaluateExpressionToTrue(s,i,k-1,true);
        int lf=memoizedEvaluateExpressionToTrue(s,i,k-1,false);
        int rt=memoizedEvaluateExpressionToTrue(s,k+1,j,true);
        int rf=memoizedEvaluateExpressionToTrue(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue==true)
                ans+=lt*rt;
            else
                ans+=lf*rt+lf*rf+lf*rf;
        }
        else if(s[k]=='|')
        {
            if(isTrue==true)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(s[k]=='^')
        {
            if(isTrue==true)
                ans+=lf*rt+lt*rf;
            else
                ans+=lt*rt+lf*rf;
        }
    }
    return mp[temp]=ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<memoizedEvaluateExpressionToTrue(s,0,s.length()-1,true)<<endl;
    return 0;
}