#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
  //  adj[v].push_back(u);
}

void DFSUtil(vector<int> adj[],int s,int v,int tc[][100])
{
    tc[s][v]=true;
    for(int i=0;i<adj[v].size();i++)
        if(tc[s][i]==false)
        DFSUtil(adj,s,i,tc);
}

void TransitiveClosure(vector<int> adj[],int v,int tc[][100])
{
    for(int i=0;i<v;i++)
        DFSUtil(adj,i,i,tc);

    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout<<tc[i][j]<<" ";
        cout<<'\n';
    }
}
int main()
{
    int v=4;
    int tc[100][100];
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);
    TransitiveClosure(adj,v,tc);
}


