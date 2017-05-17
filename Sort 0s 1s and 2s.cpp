#include<iostream>
using namespace std;
int main()
{
    int a[]={0,0,0,1,1,2,2,2,1,1,0,0,1,1,2,1,2,1,0,0,2,0,1,0,1};
    int n=sizeof(a)/sizeof(a[0]);
    int l=0,m=0,h=n-1;
    while(m<=h)
    {
        if(a[m]==0)
        {
            int temp=a[l];
            a[l]=a[m];
            a[m]=temp;
            l++;m++;

        }
        else if(a[m]==1)
        {
            m++;

        }
        else if(a[m]==2)
        {
            int temp=a[m];
            a[m]=a[h];
            a[h]=temp;
            h--;

        }

    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
