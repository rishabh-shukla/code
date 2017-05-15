#include<iostream>
using namespace std;
int main()
{
    int a[]={2,2,2,2,2,2,2,3,3,3,3,4,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int i,count=1;
    int major=0;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[major])
            count++;
        else count--;
        if(count==0)
            {
                major=i;
                count=1;
            }
    }
    count=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==a[major])
            count++;
    }
    if(count>n/2)
        cout<<a[major];
    else
        cout<<"No major";

}
