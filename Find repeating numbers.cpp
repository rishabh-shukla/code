#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,3,5};
    int n=sizeof(a)/sizeof(a[0]);
    int prod=1,sum=0;
    for(int i=0;i<n;i++)
    {
        prod*=a[i];
        sum+=a[i];
    }
    int p=1,s=0;
    for(int i=1;i<=n-2;i++)
    {
        p*=i;
        s+=i;
    }
    p=prod/p;
    s=sum-s;
    int D = sqrt(s*s - 4*p);
    int x = (D + s)/2;
    int y = (s - D)/2;
    cout<<x<<" "<<y;
}
