#include<iostream>
using namespace std;
int main()
{
    bool a[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int curr=0,pz=-1,ppz=-1,m=0;
    int index;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            if(i-ppz>m)
            {
                m=i-ppz;
                index=i;
            }
            ppz=pz;
            pz=i;
        }
    }
    if(n-ppz>m)
        index=pz;
    cout<<index;
}
