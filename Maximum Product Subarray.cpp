#include<iostream>
using namespace std;
int main()
{
    int a[]={1, -2, -3, 0, 7, -8, -2};
    int n=sizeof(a)/sizeof(a[0]);
    int i,max_prod=1,min_prod=1,prod=1;
    for(i=0;i<n;i++)
    {
        if(a[i]>0)
            {
                max_prod*=a[i];
                min_prod=min(min_prod*a[i],1);
            }
        else if(a[i]==0)
            {
                min_prod=1;
                max_prod=1;
            }
        else
            {

            int temp = max_prod;
            max_prod = max(min_prod * a[i], 1);
            min_prod= temp * a[i];
            }
              if (prod <  max_prod)
          prod  =  max_prod;
    }
    cout<<prod;
}
