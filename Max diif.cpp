#include<iostream>
using namespace std;
int main()
{
    int a[]={ 7, 9, 5, 6, 3, 2 };
    int n=sizeof(a)/sizeof(a[0]);
    int i,mi=a[0],max_diff=0;
    for(i=1;i<n;i++)
    {
        mi=min(mi,a[i]);
        max_diff=max(max_diff,a[i]-mi);
    }
    cout<<max_diff;

}

