#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void topologicalSortUtil(int u,vector<int> adj[],vector<bool> &visited,stack<int> &s)
{
    visited[u]=true;
    vector<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();++i)
        if(!visited[*i])
        topologicalSortUtil(*i,adj,visited,s);

    s.push(u);
}

void topologicalSort(vector<int> adj[],int v)
{
    stack<int> s;
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(visited[i]==false)
        topologicalSortUtil(i,adj,visited,s);

    while(s.empty()==false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
int main()
{
    int v=6;
    vector<int> adj[v];
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 0);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    topologicalSort(adj,v);
}

