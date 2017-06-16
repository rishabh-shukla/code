#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack <int> s;
    char c[]="123456";
    for(int i=0;c[i];i++)
    {
        s.push(c[i]-'0');
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
