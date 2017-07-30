#include<iostream>
using namespace std;
bool isPerfect(int n)
{
    int i;
    int sum=1;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
            sum=sum+i+n/i;
    if(sum==n && n!=1)
        return true;
    return false;
}
int main()
{
    for(int i=2;i<1000;i++)
        if(isPerfect(i))
            cout<<i<<'\n';
}
