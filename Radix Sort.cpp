#include<iostream>
using namespace std;
void count_sort(int arr[],int n,int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
int main()
{
    int a[]={170, 45, 75, 90, 802, 24, 2, 66};
    int n=sizeof(a)/sizeof(a[0]);
    int i;
    int m=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    for(i=1;m/i>0;i*=10)
        count_sort(a,n,i);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
