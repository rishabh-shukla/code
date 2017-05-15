#include<iostream>
using namespace std;
int main()
{
    int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int n=sizeof(a)/sizeof(a[0]);
    int max_so_far=0,max_here=0;
    for(int i=0;i<n;i++)
    {
        max_here+=a[i];
        if(max_here<0)
            max_here=0;
        if(max_so_far<max_here)
            max_so_far=max_here;
    }
    cout<<max_so_far;
}
