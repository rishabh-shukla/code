#include<iostream>
using namespace std;
int main()
{
    int a[]={15, 2, 4, 8, 9, 5, 10, 23, 2, 4, 8, 9, 5};
    int n=sizeof(a)/sizeof(a[0]);
    int i,curr_sum=a[0],sum=23,s=0;
    for(i=1;i<n;i++)
    {
        while(curr_sum>sum && s<i-1)
        {
            curr_sum-=a[s];
            s++;
        }
        if(curr_sum==sum)
            cout<<"Between "<<s<<" and "<< i-1<<'\n';
        if(i<n)
            curr_sum+=a[i];
    }
}
