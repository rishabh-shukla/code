#include<iostream>
#include<limits.h>
using namespace std;
int max_crossing_sum(int a[],int l,int m,int r)
{
    int sum=0,lsum=INT_MIN,rsum=INT_MIN,i;
    for(i=m;i>=l;i--)
    {
        sum=sum+a[i];
        if(sum>lsum)
            lsum=sum;
    }
    sum=0;
    for(i=m+1;i<=r;i++)
    {
        sum+=a[i];
        if(sum>rsum)
            rsum=sum;
    }
    return lsum+rsum;
}
int max_sum(int a[],int l,int r)
{
    if(l==r)
        return a[l];
    int m=(l+r)/2;
    return max(max_sum(a,l,m),
    max(max_sum(a,m+1,r),
    max_crossing_sum(a,l,m,r)));
}
int main()
{
    int a[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<max_sum(a,0,n-1);
}
