#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

bool isCyclicUtil(int u,vector<int> adj[],vector<bool> &visited,vector<bool> rec)
{
    if(visited[u]==false)
    {
        visited[u]=true;
        rec[u]=true;
        vector<int>::iterator i;
        for(i=adj[u].begin();i<adj[u].end();i++)
        {
            if(visited[*i]==false)
            {
                if(isCyclicUtil(*i,adj,visited,rec));
                return true;
            }
            else if(rec[*i])
                return true;
        }
    }
    rec[u]=false;
    return false;
}

bool isCyclic(vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    vector<bool> rec(v,false);
    for(int i=0;i<v;i++)
        if(isCyclicUtil(i,adj,visited,rec));
            return true;
    return false;
}
int main()
{
    int v=4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    cout<<isCyclic(adj,v);
}



