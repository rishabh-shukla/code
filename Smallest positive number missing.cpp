#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={2, 3, 7, 6, 8, -1, -10, 15};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]<=0)
        {
            swap(a[i],a[j]);
            j++;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(abs(a[i]) - 1 < n && a[abs(a[i]) - 1] > 0)
            a[abs(a[i]) - 1] = -a[abs(a[i]) - 1];
    }

  // Return the first index value at which is positive
    for(i = 0; i < n; i++)
        if (a[i] > 0)
            {cout<< i+1;return 0;}
    cout<<n;
}
