#include<iostream>
using namespace std;
int main()
{
    int a[]={1,5,9,10,15,20};
    int b[]={2,3,8,13};
    int n=6,m=4;
    int i,j;
    for(i=m-1;i>-1;i--)
    {
        int last=a[n-1];
        j=n-1;
        while(a[j]>b[i])
        {
            a[j]=a[j-1];
            j--;
        }
        if(j!=n-1 ||last>b[i])
        {
            a[j+1]=b[i];
            b[i]=last;
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<'\n';
    for(i=0;i<m;i++)
        cout<<b[i]<<" ";

}
