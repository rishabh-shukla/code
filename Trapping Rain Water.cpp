#include<iostream>
using namespace std;
int main()
{
    int a[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n=sizeof(a)/sizeof(a[0]);
    int i,l[n],r[n];
    int water=0;
    l[0]=a[0];
    r[n-1]=a[n-1];
    for(i=1;i<n;i++)
        l[i]=max(l[i-1],a[i]);
    for(i=n-2;i>=0;i--)
        r[i]=max(r[i+1],a[i]);
    for(i=0;i<n;i++)
        water+=min(l[i],r[i])-a[i];
    cout<<water;
}
