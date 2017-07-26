#include<iostream>
#include<limits.h>
#define V 9
using namespace std;

int minDist(int dist[],bool set[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
        if(set[i]==false && dist[i]<min)
            min=dist[i],min_index=i;
    return min_index;
}

void print(int dist[],int n)
{
    cout<<"Vertex  Distance from Source\n";
    for(int i=0;i<n;i++)
        cout<<i<<"   "<<dist[i]<<'\n';
}
void dijsktra(int graph[V][V],int src)
{
    int dist[V];
    bool set[V];
    for(int i=0;i<V;i++)
        dist[i]=INT_MAX,set[i]=false;

    dist[src]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=minDist(dist,set);
        set[u]=true;

        for(int i=0;i<V;i++)
            if(!set[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u]+graph[u][i]<dist[i])
                dist[i]=dist[u]+graph[u][i];
    }
    print(dist,V);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    dijsktra(graph,0);
}
