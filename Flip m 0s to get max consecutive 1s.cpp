#include<iostream>
using namespace std;
int main()
{
    int a[]={1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int m=2;
    int n=sizeof(a)/sizeof(a[0]);
    int l=0,r=0,max=0;
    int bl=0;
    int z=0;
    while(r<n)
    {
        if(z<=m)
        {
            if(a[r]==0)
                z++;
            r++;
        }
        if(z>m)
        {
            if(a[l]==0)
                z--;
            l++;
        }
        if(r-l>max)
        {
            max=r-l;
            bl=l;
        }
    }
    for(int i=0;i<max;i++)
    {
        if(a[bl+i]==0)
            cout<<bl+i<<" ";
    }
}
