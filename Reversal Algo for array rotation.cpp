#include<iostream>
#include<algorithm>
using namespace std;
void array_reverse(int a[],int l,int r)
{
    int temp;
    while(l<r)
    {
        temp=a[l];
        a[l]=a[r];
        a[r]=temp;
        l++;r--;
    }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,11,12,13};
    int d=2;
    int n=sizeof(a)/sizeof(a[0]);
    array_reverse(a,0,d-1);
    array_reverse(a,d,n-1);
    array_reverse(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
