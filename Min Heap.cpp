#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(5);
    pq.push(15);
    pq.push(25);
    pq.push(35);
    while(!pq.empty())
    {
        cout<<pq.top();
        pq.pop();
    }
}
