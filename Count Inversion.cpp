#include<iostream>
using namespace std;
int main()
{
    int a[] ={2,4,1,3,5};//{5,8,3,8,5,5,8,3,2,3,5,3};
    int i,j,count=0;
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        if(a[i]>a[j])
            count++;
    cout<<count;
}
