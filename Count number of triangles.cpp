#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={10, 21, 22, 100, 101, 200, 300};
    int n=sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    int i,j,k;
    int c=0;
    for(i=0;i<n-1;i++)
    {
        k=i+2;
        for(j=i+1;j<n;j++)
        {
             while (k < n && a[i] + a[j] > a[k])
               ++k;
            c+=k-j-1;
        }
    }
    cout<<c;
}
