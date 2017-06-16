#include<iostream>
#include<stack>
using namespace std;
int main()
{
    char exp[]="231*+9-";
    stack<int> s;
    for(int i=0;exp[i];i++)
    {
        if(isdigit(exp[i]))
            s.push(exp[i]-'0');
        else
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            switch(exp[i])
            {
                case '+':s.push(a+b);break;
                case '-':s.push(b-a);break;
                case '*':s.push(a*b);break;
                case '/':s.push(b/a);break;
            }

        }
    }
    cout<<s.top();
}
