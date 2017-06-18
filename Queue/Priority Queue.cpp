#include<iostream>
#include<queue>
using namespace std;
void print(priority_queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.top()<<' ';
        q.pop();
    }
    cout<<'\n';
}
int main()
{
    priority_queue <int> q;
    q.push(10);
    q.push(50);
    q.push(30);
    q.push(5);
    q.push(1);
    print(q);
    cout<<q.size()<<' '<<q.top();

}
