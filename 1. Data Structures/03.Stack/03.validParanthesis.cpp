#include <bits/stdc++.h>
using namespace std;
int validParenthesis(string str)
{
    stack<char> s;
    for (int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            s.push(str[i]);
        if(str[i]==')' || str[i]=='}' || str[i]==']')
            if(!s.empty())
                s.pop();
    }
    if(s.empty())
        return 1;
    else
        return 0;
}
int main()
{
    string str;
    cin>>str;
    if(validParenthesis(str)==1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;
}


