#include <bits/stdc++.h>
using namespace std;
int isOperand(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return 0;
    else
        return 1;
}
int calculate(int a,int b,char c)
{
    int result;
    switch(c)
    {
        case '+':
        result=a+b;
        break;
        case '-':
        result=a-b;
        break;
        case '*':
        result=a*b;
        break;
        case '/':
        result=a/b;
        break;
        case '^':
        result=a^b;
        break;
    }
    return result;
}
void evaluate(string str)
{
    stack<int> s;
    int x,y;
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        if(isOperand(c))
            s.push(c-'0');
        else
        {
            y=s.top();
            s.pop();
            x=s.top();
            s.pop();
            s.push(calculate(x,y,c));
        }
    }
    cout<<s.top()<<endl;
    s.pop();
}
int main()
{
    string str;
    cin>>str;
    evaluate(str);
    return 0;
}
