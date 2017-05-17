#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1, 2, 3, 1, 3, 6, 6,6,6};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        a[a[i]%n]+=n;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]/n>1)
            cout<<i<<" ";
    }
}
