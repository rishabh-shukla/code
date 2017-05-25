#include<iostream>
using namespace std;
int main()
{
    int a[]={- 8, 1, 4, 2, -6};
    int n=sizeof(a)/sizeof(a[0]);
    int sum=6;
    int curr_sum=0,l=n-1;
    int s=0,e=0;
    while(e<n)
    {
        while(e<n && curr_sum<=sum)
        {
            if(curr_sum<0 && sum>0)
            {
                s=e;
                curr_sum=0;
            }
            curr_sum+=a[e++];
        }
        while(curr_sum>sum && s<n)
        {
            if(e-s<l)
                l=e-s;
            curr_sum-=a[s++];

        }
    }
    cout<<l;
}
