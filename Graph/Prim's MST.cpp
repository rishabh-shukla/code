#include<iostream>
#include<limits.h>
using namespace std;
int min(int key[],bool mset[])
{
    int min=INT_MAX;
    int index;
    int i;
    for(i=0;i<5;i++)
        if(mset[i]==false &&key[i]<min)
            min=key[i],index=i;
        return index;
}
int print(int parent[],int n,int graph[5][5])
{
    cout<<"Edge   Weight\n";
    for(int i=1;i<5;i++)
    {
        cout<<parent[i]<<" - "<<i<<"    "<<graph[i][parent[i]]<<'\n';
    }
}

void primMst(int graph[5][5])
{
    int parent[5];
    int key[5];
    bool mset[5];
    for (int i = 0; i < 5; i++)
        key[i] = INT_MAX, mset[i] = false;
    key[0]=0;
    parent[0]=-1;

    for(int count=0;count<4;count++)
    {
        int u=min(key,mset);
        mset[u]=true;
        for(int i=0;i<5;i++)
            if(graph[u][i] && mset[i]==false && graph[u][i]<key[i])
                parent[i]=u,key[i]=graph[u][i];
    }

    print(parent,5,graph);
}
int main()
{
    int graph[5][5]={{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
    primMst(graph);
}
