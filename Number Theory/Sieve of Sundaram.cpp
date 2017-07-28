#include<iostream>
using namespace std;

void Sieve(int n)
{
    int n1=(n-2)/2;
    bool marked[n1+1];
    for(int i=1;i<=n1;i++)
        for(int j=i;(i+j+2*i*j)<=n1;j++)
            marked[i+j+2*i*j]=true;
    if(n>2)
        cout<<2<<" ";
    for(int i=1;i<=n1;i++)
        if(marked[i]==false)
            cout<<2*i+1<<" ";
}
int main()
{
    int n=100;
    Sieve(n);
}
