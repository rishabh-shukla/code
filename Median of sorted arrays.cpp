#include<iostream>
using namespace std;

int median(int a[],int n)
{
    if(n%2==1)
        return a[n/2];
    else
        return (a[n/2]+a[n/2-1])/2;

}

int get_median(int a[],int b[],int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (a[0] + b[0])/2;
    if (n == 2)
        return (max(a[0], b[0]) + min(a[1], b[1])) / 2;
    int m1=median(a,n);
    int m2=median(b,n);
    if(m1==m2)
        return m1;
    if(m1<m2)
    {
        if(n%2==0)
            return get_median(a+n/2-1,b,n-n/2+1);
        return get_median(a+n/2,b,n-n/2);
    }
    if(n%2==0)
        return get_median(a,b+n/2-1,n-n/2+1);
    return get_median(a,b+n/2,n-n/2);
}

int main()
{
    int a[]={1, 12, 15, 26, 38};
    int b[]={2, 13, 17, 30, 45};
    int n=sizeof(a)/sizeof(a[0]);
    int ans=get_median(a,b,n);
    cout<<ans;
}
