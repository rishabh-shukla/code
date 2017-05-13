#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,a[100005];
        cin>>n;
        for(i=1;i<=2*n;i++)
            cin>>a[i];
            int m=2*n;
        sort(a+1,a+m+1);

        int b[100005];
        for(i=1;i<=2*n;i++)
            {
               if(i%2==0)
                b[i]=a[n+i/2];
               else
                b[i]=a[(i/2)+1];
            }
            cout<<b[n+1]<<'\n';
        for(i=1;i<=2*n;i++)
                cout<<b[i]<<" ";
                cout<<'\n';
    }
}
