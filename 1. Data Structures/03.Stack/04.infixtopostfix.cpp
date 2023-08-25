#include <bits/stdc++.h>
using namespace std;
int precedence(char c)
{
    if(c=='^')
        return 3;
    else if(c=='/' || c=='*')
        return 2;
    else if(c=='+' || c=='-')
        return 1;
    else
        return -1;
}
void infixtopostfix(string str)
{
    stack<char> s;
    string result;
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            result=result+c;
        else if(c=='(')
            s.push(c);
        else if(c==')')
        {
            while(s.top()!='(')
            {
                result = result+s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && precedence(c)<=precedence(s.top()))
            {
                if(c=='^' && s.top()!='^')
                    break;
                else
                {
                    result=result+s.top();
                    s.pop();
                }
            } 
            s.push(c);               
        }
    }
    while(!s.empty())
    {
        result = result+s.top();
        s.pop();
    }
    cout<<result<<endl;
}
int main()
{
    string str;
    cin>>str;
    infixtopostfix(str);
    return 0;
}