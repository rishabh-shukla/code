#include<iostream>
using namespace std;
int main()
{
    int a[]={1, 12, -5, -6, 50, 3};
    int n=sizeof(a)/sizeof(a[0]);
    int i,csum[n];
    int k=4;
    csum[0]=a[0];
    for(i=1;i<n;i++)
        csum[i]=csum[i-1]+a[i];
    int sum=csum[k-1],s=k-1;
    int j;
    for(i=k;i<n;i++)
    {
        s=csum[i]-csum[i-k];
        if(s>sum)
            {
                sum=s;
                j=i;
            }
    }
    cout<<j-k+1<<" "<<s;
}
