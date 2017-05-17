#include<iostream>
using namespace std;
int main()
{
    int a[]={3,4,2,6,8,7,5};
    int n=sizeof(a)/sizeof(a[0]);
    int i,mx=a[0],mn=a[0],sum=a[0];
    for(i=1;i<n;i++)
    {
        sum+=a[i];
        if(a[i]>mx)
            mx=a[i];
        if(a[i]<mn)
            mn=a[i];
    }
    int p=(mx*(mx+1))/2-(mn*(mn-1))/2;
    if(sum==p)
        cout<<"YES";
    else cout <<"NO";

}
