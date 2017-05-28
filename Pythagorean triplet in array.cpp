#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[]={3,1,4,6,5};
    int n=5;
    int i;
    for(i=0;i<n;i++)
    {
        a[i]*=a[i];
    }
    sort(a,a+n);
    for(i=n-1;i>=2;i--)
    {
        int l=0,r=i-1;
        while(l<r)
        {
            if(a[l]+a[r]==a[i])
                {
                    cout<<"YES";break;
                }
            else
            if(a[l]+a[r]<a[i])
                l++;
            else
                r--;
        }
    }
}
