#include<iostream>
using namespace std;
int main()
{
    int a[]={100, 180, 260, 310, 40, 535, 695};
    int n=sizeof(a)/sizeof(a[0]);
    int i=0,c=0;
    while(i<n-1)
    {
        while(i<n-1 && a[i+1]<=a[i])
            i++;
        if(i==n-1)
            break;
        cout<<"Buy on "<<i<<'\n';
        while(i<n && a[i+1]>=a[i])
            i++;
        cout<<"Sell on "<<i<<'\n';
        c++;
    }
    if(c==0)
    cout<<"No buying and selling";
}
