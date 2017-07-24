#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

bool DLS(vector<int> adj[],int v,int src,int target,int limit)
{
    if(src==target)
        return true;
    if(limit<=0)
        return false;

    for(auto i=adj[src].begin();i!=adj[src].end();i++)
        if(DLS(adj,v,*i,target,limit-1)==true)
        return true;
    return false;
}

bool IDFS(vector<int> adj[],int v,int src,int target,int max_depth)
{
    for(int i=0;i<max_depth;i++)
        if(DLS(adj,v,src,target,i)==true)
        return true;
    return false;
}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    cout<<IDFS(adj,v,0,6,3);
}


