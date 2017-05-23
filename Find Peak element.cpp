#include<iostream>
using namespace std;
int peak(int a[],int l,int r,int n)
{
    int m=(l+r)/2;
    if((m==0 || a[m-1]<=a[m])&&(m==n-1 || a[m+1]<=a[m]))
        return m;
    else if (m > 0 && a[m-1] > a[m])
        return peak(a, l, (m -1), n);
    else return peak(a, (m + 1), r, n);
}
int main()
{
    int a[]={1, 3, 20, 4, 1, 0};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<peak(a,0,n-1,n);
}
