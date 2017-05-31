#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4};
    int n=4,l=1,res=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
            l++;
        else
        {
            res+=(l*(l-1))/2;
            l=1;
        }
    }
    if(l>1)
        res+=(l*(l-1))/2;
    cout<<res;
}
