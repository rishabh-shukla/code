#include<iostream>
using namespace std;
int main()
{
    int a[]={1,1,3,5,6};
    int n=5;
    int res=1;
    for(int i=0;i<n && a[i]<=res;i++)
    {
        res+=a[i];
    }
    cout<<res;
}
