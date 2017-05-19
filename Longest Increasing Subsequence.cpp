#include<iostream>
using namespace std;
int CeilIndex(int v[],int l,int r,int key)
{
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}
int main()
{
    int a[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n=sizeof(a)/sizeof(a[0]);
    int b[n];
    int i;
    b[0]=a[0];
    int l=1;
    for(i=1;i<n;i++)
    {
        if(a[i]<b[0])
            b[0]=a[i];
        else if(a[i]>b[l-1])
            b[l++]=a[i];
        else
            b[CeilIndex(b, -1, l-1, a[i])] = a[i];
    }
    cout<<l;
}
