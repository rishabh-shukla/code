#include <iostream>
#include <algorithm>
using namespace std;
struct Interval
{
    int start;
    int end;
};
bool compareInterval(Interval i1, Interval i2)
{  return (i1.start < i2.start)? true: false; }
bool isOverlap(Interval arr[], int n)
{
    sort(arr, arr+n, compareInterval);
    for (int i=1; i<n; i++)
        if (arr[i-1].end > arr[i].start)
            return true;
    return false;
}
int main()
{
    Interval arr1[] =  {{1,3}, {7,9}, {4,6}, {10,13}};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    isOverlap(arr1, n1)? cout << "Yes\n" : cout << "No\n";

    Interval arr2[] =  { {6,8},{1,3},{2,4},{4,7} };
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    isOverlap(arr2, n2)? cout << "Yes\n" : cout << "No\n";
}
