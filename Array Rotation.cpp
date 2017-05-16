#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,1,2,3};
    int d=7;
    int n=sizeof(a)/sizeof(a[0]);
    int g=__gcd(n,d);
    int temp,j,i,k;
    for(i=0;i<g;i++)
    {
        temp=a[i];
        j=i;
        while(1)
        {
            k=j+d;
            if(k>=n)
                k-=n;
            if(k==i)
                break;
            a[j]=a[k];
            j=k;
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
