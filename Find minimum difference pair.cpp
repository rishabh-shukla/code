#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={1, 5, 3, 19, 18, 25};
    int n=sizeof(a)/sizeof(a[0]);
    int i,diff=1000;
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i]<diff)
            diff=a[i+1]-a[i];
    }
    cout<<diff;
}
