#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char a[]="geeksforgeeks";
    int n=sizeof(n)/sizeof(a[0]);
    int r[256]={0};
    char b[n];
    int i;
    for(i=0;a[i];i++)
        r[a[i]]++;
    for(i=1;i<=256;i++)
        r[i]+=r[i-1];
    for(i=0;a[i];++i)
    {
        b[r[a[i]]-1]=a[i];
        --r[a[i]];
    }
    printf("%s",b);
}
