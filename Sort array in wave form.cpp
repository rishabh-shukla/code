#include<iostream>
using namespace std;
int main()
{
    int a[]={10, 90, 49, 2, 1, 5, 23};
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && a[i-1]>a[i])
            swap(a[i-1],a[i]);
        if(i<n-1 && a[i+1]>a[i])
            swap(a[i],a[i+1]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
