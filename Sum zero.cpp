#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
    int a[]={0, 60, -10,0, 70, -80, 85};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    int l=0,r=n-1,sum,min_sum=INT_MAX;
    int min_l=l,min_r=n-1;
   // l++;r--;
    while(l<r)
    {
        sum=a[l]+a[r];
        if(abs(sum)<abs(min_sum))
            {
                min_sum=sum;
                min_l=l;
                min_r=r;
            }
        if(sum<0)
            l++;
        else r--;
    }

    cout<<a[min_l]<<" "<<a[min_r];
}
