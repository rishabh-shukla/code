#include<iostream>
#include<climits>
using namespace std;
#define INF INT_MAX
#define N 4
void youngify(int mat[][N], int i, int j)
{
    int downVal  = (i+1 < N)? mat[i+1][j]: INF;
    int rightVal = (j+1 < N)? mat[i][j+1]: INF;
    if (downVal==INF && rightVal==INF)
        return;
    if (downVal < rightVal)
    {
        mat[i][j] = downVal;
        mat[i+1][j] = INF;
        youngify(mat, i+1, j);
    }
    else
    {
        mat[i][j] = rightVal;
        mat[i][j+1] = INF;
        youngify(mat, i, j+1);
    }
}
int extractMin(int mat[][N])
{
    int ret = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return ret;
}
void printSorted(int mat[][N])
{
   cout << "Elements of matrix in sorted order n";
   for (int i=0; i<N*N; i++)
     cout << extractMin(mat) << " ";
}
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
}
