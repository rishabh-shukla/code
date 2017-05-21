#include<iostream>
using namespace std;
int main()
{
    int a[]={12, 11, 10, 5, 6, 2, 30};
    int n=sizeof(a)/sizeof(a[0]);
    int s[n],l[n];
    s[0]=-1;
    l[n-1]=-1;
    int i;
    int m=0,k=n-1;
    for(i=1;i<n;i++)
    {
        if(a[i]<=a[m])
        {
            m=i;
            s[i]=-1;
        }
        else s[i]=m;
    }
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>=a[k])
        {
            k=i;
            l[i]=-1;
        }
        else l[i]=k;
    }
    for(i=0;i<n;i++)
    {
        if(s[i]!=-1 && l[i]!=-1)
        {
            cout<<a[s[i]]<<" "<<a[i]<<" "<<a[l[i]];
            return 0;
        }
    }
}
