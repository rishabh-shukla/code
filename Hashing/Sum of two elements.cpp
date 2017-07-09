#include<iostream>
using namespace std;
int main()
{
    int a[]={1,4,45,6,8,10};
    int n=6;
    int sum=16;
    bool map[100000]={0};
    for(int i=0;i<n;i++)
    {
        int t=sum-a[i];
        if(t>=0 && map[t]==1)
            cout<<a[i]<<" "<<t<<'\n';
        map[a[i]]=1;
    }
}
