#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    for (int i=0; i<n; i++)
        {
            m[arr[i]]++;
            cout<<m[arr[i]]<<" ";
        }
    int twice_count = 0;
    for (int i=0; i<n; i++)
    {
        twice_count += m[sum-arr[i]];
        if (sum-arr[i] == arr[i])
            twice_count--;
    }
    return twice_count/2;
}
int main()
{
    int arr[] = {1, 5, 7, -1, 5} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
}
