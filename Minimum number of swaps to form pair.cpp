#include<bits/stdc++.h>
using namespace std;
void updateindex(int index[], int a, int ai, int b, int bi)
{
    index[a] = ai;
    index[b] = bi;
}
int minSwapsUtil(int arr[], int pairs[], int index[], int i, int n)
{
    if (i > n) return 0;
    if (pairs[arr[i]] == arr[i+1])
         return minSwapsUtil(arr, pairs, index, i+2, n);

    int one = arr[i+1];
    int indextwo = i+1;
    int indexone = index[pairs[arr[i]]];
    int two = arr[index[pairs[arr[i]]]];
    swap(arr[i+1], arr[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int a = minSwapsUtil(arr, pairs, index, i+2, n);

    swap(arr[i+1], arr[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    one = arr[i], indexone = index[pairs[arr[i+1]]];

    two = arr[index[pairs[arr[i+1]]]], indextwo = i;
    swap(arr[i], arr[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int b = minSwapsUtil(arr, pairs, index, i+2, n);

    swap(arr[i], arr[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    return 1 + min(a, b);
}
int minSwaps(int n, int pairs[], int arr[])
{
    int index[2*n + 1]; // To store indices of array elements
    for (int i = 1; i <= 2*n; i++)
        index[arr[i]] = i;
    return minSwapsUtil(arr, pairs, index, 1, 2*n);
}
int main()
{
    int arr[] = {0, 3, 5, 6, 4, 1, 2};

    int pairs[] = {0, 3, 6, 1, 5, 4, 2};
    int m = sizeof(arr)/sizeof(arr[0]);

    int n = m/2;  // Number of pairs n is half of total elements
    cout << "Min swaps required is " << minSwaps(n, pairs, arr);
    return 0;
}
