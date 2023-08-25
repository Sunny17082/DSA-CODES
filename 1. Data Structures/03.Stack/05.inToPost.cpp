#include <bits/stdc++.h>
using namespace std;
int outpre(char c)
{
    if(c=='+' || c=='-')
        return 1;
    else if(c=='/' || c=='*')
        return 3;
    else if(c=='^')
        return 6;
    else if(c=='(')
        return 7;
    else
        return -1;
}
int inpre(char c)
{
    if(c=='+' || c=='-')
        return 2;
    else if(c=='/' || c=='*')
        return 4;
    else if(c=='^')
        return 5;
    else if(c=='(')
        return 0;
    else
        return -1;
}
int isoperand(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='(' || c==')')
        return 0;
    else
        return 1;
}
void inToPost(string str)
{
    stack<char> s;
    string result;
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        if(isoperand(c))
            result+=c;
        else if(c==')')
        {
            while(s.top()!='(')
            {
                result+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            if(s.empty() || outpre(c)>inpre(s.top()))
                s.push(c);
            else
            {
                while(!s.empty() && outpre(c)<inpre(s.top()))
                {
                    result+=s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    while(!s.empty())
    {
        result+=s.top();
        s.pop();
    }
    cout<<result<<endl;
}
int main()
{
    string str;
    cin>>str;
    inToPost(str);
    return 0;
}