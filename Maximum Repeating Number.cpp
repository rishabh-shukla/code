#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,3,4,5,2,2,1,3,4,3};
    int n=sizeof(a)/sizeof(a[0]);
    int i,k=6;
    for(i=0;i<n;i++)
    {
        a[a[i]%k]+=k;
    }
    int m=a[0],r=0;
    for(i=1;i<n;i++)
    {
        if(a[i]>m)
        {
            m=a[i];
            r=i;
        }
    }
    cout<<r;
}
