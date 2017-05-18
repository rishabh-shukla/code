#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
    int b=1,c=2,a[]={3,4,2,5,3,2,6,1,3,4,2,4,5,6,7,1,3,4,2};
    int prev;
    int min_dist=INT_MAX;
    int i,n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
    {
        if((a[i]==b) || (a[i]==c))
            {
                prev=i;
                break;
            }
    }
    for(;i<n;i++)
    {
        if (a[i] == b || a[i] == c)
      {
           if ( a[prev] != a[i] && (i - prev) < min_dist )
          {
             min_dist = i - prev;
             prev = i;
          }
          else
             prev = i;
      }
    }
    cout<<min_dist;

}
