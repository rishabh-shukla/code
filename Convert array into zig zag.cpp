#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a)/sizeof(a[0]);
    int i;
    bool flag=1;
    for(i=0;i<n;i++)
    {
        if(flag)
        {
            if(a[i]>a[i+1])
                swap(a[i],a[i+1]);
        }
        else
        {
            if(a[i]<a[i+1])
                swap(a[i],a[i+1]);
        }
        flag=1-flag;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}

