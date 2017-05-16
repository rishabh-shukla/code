#include<iostream>
using namespace std;
int main()
{
    int a[]={5,  5, 10, 40, 50, 35};
    int n=sizeof(a)/sizeof(a[0]);
    int incl=a[0],excl=0,p_excl=0;
    for(int i=1;i<n;i++)
    {
        p_excl=max(incl,excl);
        incl=excl+a[i];
        excl=p_excl;
    }
    cout<<sizeof(a[0])<<" "<<max(excl,incl);
}
