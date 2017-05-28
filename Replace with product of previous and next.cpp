#include<iostream>
using namespace std;
int main()
{
    int a[]={2,3,4,5,6};
    //      6,8,15,24,30
    int n=5,i;
    int p=a[0];
    a[0]*=a[1];
    for(i=1;i<n-1;i++)
    {
        int curr=a[i];
        a[i]=p*a[i+1];
        p=curr;
    }
    a[n-1]=p*a[n-1];
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
