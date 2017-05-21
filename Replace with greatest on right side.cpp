#include<iostream>
using namespace std;
int main()
{
    int a[]={16, 17, 4, 3, 5, 2};
    int n=sizeof(a)/sizeof(a[0]);
    int i,g=a[n-1];
    a[n-1]=-1;
    for(i=n-2;i>-1;i--)
    {
        int t=g;
        if(a[i]>g)
            g=a[i];
        a[i]=t;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
