#include<iostream>
using namespace std;
int main()
{
    int a[]={12,65,34,98,2,45};
    int n=sizeof(a)/sizeof(a[0]);
    int f=max(a[0],a[1]),s=min(a[0],a[1]);
    int i;
    for(i=2;i<n;i++)
    {
        if(a[i]>f)
            {
                s=f;
                f=a[i];
            }
        else if(a[i]>s)
            s=a[i];
    }
    cout<<s+f;
}
