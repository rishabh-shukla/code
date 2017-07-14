#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isCyclicUtil(int u,vector<int> adj[],vector<bool> &visited,int parent)
{
    visited[u]=true;
    vector<int>::iterator i;
    for(i=adj[u].begin();i<adj[u].end();i++)
    {
        if(visited[*i]==false)
        {
            if(isCyclicUtil(*i,adj,visited,u));
            return true;
        }
        else if(*i!=parent)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(visited[i]==false)
        if(isCyclicUtil(i,adj,visited,-1));
            return true;
    return false;
}
int main()
{
    int v=5;
    vector<int> adj[v];
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 4);
    cout<<isCyclic(adj,v);
}


