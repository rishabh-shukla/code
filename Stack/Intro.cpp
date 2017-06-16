#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<'\n';
    s.pop();
    cout<<s.top()<<'\n';
    cout<<s.size();
    s.pop();
}
