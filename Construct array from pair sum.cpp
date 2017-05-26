#include <iostream>
using namespace std;
int main()
{
    int pair[] = {15, 13, 11, 10, 12, 10, 9, 8, 7, 5};
    int n = 5;
    int arr[n];
    arr[0] = (pair[0]+pair[1]-pair[n-1]) / 2;
    for (int i=1; i<n; i++)
        arr[i] = pair[i-1]-arr[0];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
