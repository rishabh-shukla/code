#include<iostream>
using namespace std;
int main()
{
    int a[]={7,8,9,10,1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int arrsum=0,i,val=0;
    for(i=0;i<n;i++)
       {
            arrsum+=a[i];
            val+=i*a[i];
       }
    int max=val;
    for(i=1;i<n;i++)
    {
        val+=arrsum-n*a[n-i];
        if(val>max)
            max=val;
    }
    cout<<max;
}
