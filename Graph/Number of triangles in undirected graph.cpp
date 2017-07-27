#include <bits/stdc++.h>
using namespace std;
#define V 4
void multiply(int A[][V], int B[][V], int C[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < V; k++)
                C[i][j] += A[i][k]*B[k][j];
        }
    }
}
int getTrace(int graph[][V])
{
    int trace = 0;
    for (int i = 0; i < V; i++)
        trace += graph[i][i];
    return trace;
}
int triangleInGraph(int graph[][V])
{
    int aux2[V][V];  // To Store graph^2
    int aux3[V][V]; // To Store graph^3
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            aux2[i][j] = aux3[i][j] = 0;
    multiply(graph, graph, aux2);
    multiply(graph, aux2, aux3);
    int trace = getTrace(aux3);
    return trace / 6;
}
int main()
{
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                      };
    printf("Total number of Triangle in Graph : %d\n",
            triangleInGraph(graph));
}
