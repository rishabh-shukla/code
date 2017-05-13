#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,m=-1;
        cin>>n;
        for(int i=0;i<n;i++)
            {
                cin>>a;
                m=max(m,a);
            }
            cout<<n-m<<'\n';
    }
}
