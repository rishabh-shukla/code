#include<bits/stdc++.h>
using namespace std;
int longestCommonSum(bool arr1[], bool arr2[], int n)
{
    int maxLen = 0;
    int preSum1 = 0, preSum2 = 0;
    int diff[2*n+1];
    memset(diff, -1, sizeof(diff));

    for (int i=0; i<n; i++)
    {
        preSum1 += arr1[i];
        preSum2 += arr2[i];

        int curr_diff = preSum1 - preSum2;
        int diffIndex = n + curr_diff;

        if (curr_diff == 0)
            maxLen = i+1;

        else if ( diff[diffIndex] == -1)
            diff[diffIndex] = i;

        else
        {
            int len = i - diff[diffIndex];

            if (len > maxLen)
                maxLen = len;
        }
    }
    return maxLen;
}
int main()
{
    bool  arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool  arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Length of the longest common span with same "
            "sum is "<< longestCommonSum(arr1, arr2, n);
}
