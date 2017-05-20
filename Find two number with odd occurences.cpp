#include<iostream>
using namespace std;
int main()
{
    int a[]={1,1,2,2,2,2,3,4,4,5,5,6,6,6,6,7,7,7};
    int n=sizeof(a)/sizeof(a[0]);
    int i,xor1=0,xor2;
    for(i=0;i<n;i++)
        xor1=xor1^a[i];
    int x=0,y=0;
    int bit=xor1 & ~(xor1-1);
    for(i=0;i<n;i++)
    {
        if(a[i]&bit)
            x=x^a[i];
        else
            y=y^a[i];
    }
    cout<<x<<" "<<y;
}
