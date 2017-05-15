#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,1,2,3,5,2,2,2,2,3,3},i,res=0;
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++)
        res=a[i]^res;
    cout<<res;
}
