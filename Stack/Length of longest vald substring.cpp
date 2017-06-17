#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string s="((()()";
    int n=s.length();
    stack<int> stk;
    stk.push(-1);
    int r=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            stk.push(i);
        else
        {
            stk.pop();
            if(!stk.empty())
                r=max(r,i-stk.top());

            else stk.push(i);
        }
    }
    cout<<r;
}
