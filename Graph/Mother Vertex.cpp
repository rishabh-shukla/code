#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}

void DFSUtil(int u,vector<int> adj[],vector<bool> &visited)
{
    visited[u]=true;
   // cout<<u<<'\n';
    for(int i=0;i<adj[u].size();i++)
        if(visited[adj[u][i]]==false)
        DFSUtil(adj[u][i],adj,visited);
}

void DFS(vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++)
        if(visited[i]==false)
        DFSUtil(i,adj,visited);
}
int mother(vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    int last=0;
    for(int i=0;i<v;i++)
        if(visited[i]==false)
        {
            DFSUtil(i,adj,visited);
            last=i;
        }

    fill(visited.begin(),visited.end(),false);
    DFSUtil(last,adj,visited);
    for(int i=0;i<v;i++)
        if(visited[i]==false)
        return -1;
    return last;

}
int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 6, 4);
    addEdge(adj, 5, 6);
    addEdge(adj, 5, 2);
    addEdge(adj, 6, 0);
    cout<<"Mother is "<<mother(adj,v);
}


