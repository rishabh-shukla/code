#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int a[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n=sizeof(a)/sizeof(a[0]);
    int dp[n];
    int m,i,j;
    dp[n-1]=0;
    for(i=n-2;i>=0;i--)
    {
        if(a[0]==0)
            {
                cout<<"Not Possible";
                break;
            }
        else if(a[i]>=n-i-1)
            dp[i]=1;
        else
        {
            m = INT_MAX;

            for (j = i+1; j < n && j <= a[i] + i; j++)
            {
                if (m > dp[j])
                    m = dp[j];
            }

            if (m != INT_MAX)
              dp[i] = m + 1;
            else
              dp[i] = m;
        }
    }


}
