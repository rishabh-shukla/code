#include<iostream>
using namespace std;
int find_min(int a[],int l,int r)
{
    if(r<l)
        return a[0];
    if(l==r)
        return a[l];
    int m=(l+r)/2;

    if(a[m]<a[m-1] && m>l)
        return a[m];
    if(a[m+1]<a[m] && m<r)
        return a[m+1];
    else if(a[r]>a[m])
        find_min(a,l,m-1);
    else find_min(a,m+1,r);
}
int main()
{
    int a[]={5, 6, 7, 1, 2, 3, 4};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<find_min(a,0,n-1);

}
