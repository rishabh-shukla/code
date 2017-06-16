#include<iostream>
#include<stack>
using namespace std;
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int main()
{
    char exp[]="a+b*(c^d-e)^(f+g*h)-i";
    stack<int> s;
    int i,k;
    for(i=0,k=-1;exp[i];i++)
    {
        if(isOperand(exp[i]))
            exp[++k]=exp[i];
        else if(exp[i]=='(')
               s.push(exp[i]);
        else if(exp[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                exp[++k]=s.top();
                s.pop();
            }
            if(!s.empty() && s.top()!='(')
                return -1;
            else
                s.pop();
        }
        else
        {
            while(!s.empty() && Prec(exp[i])<=Prec(s.top()))
                {
                    exp[++k]=s.top();
                    s.pop();
                }
            s.push(exp[i]);
        }
    }
    while(!s.empty())
        {
            exp[++k]=s.top();
            s.pop();
        }
        exp[++k]='\0';
        cout<<exp;
}
