#include<iostream>
using namespace std;
int main()
{
    int a[]={12, 4, 78, 90, 45, 23};
    int n=sizeof(a)/sizeof(a[0]);

    int l[n],r[n],i;
    l[0]=1,r[n-1]=1;

    for(i=1;i<n;i++)
        l[i] = (a[i] > a[i-1])? l[i-1] + 1: 1;
    for(i=n-2;i>=0;i--)
        r[i] = (a[i] > a[i+1])? r[i+1] + 1: 1;
    int m=l[0]+r[0]-1;

    for(i=1;i<n;i++)
    {
        if(l[i]+r[i]-1>m)
            m=l[i]+r[i]-1;
    }
    cout<< m;
}
