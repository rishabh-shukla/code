#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int a[]={11,13,21,3};
    stack<int> s;
    int n=sizeof(a)/sizeof(a[0]);
    s.push(a[0]);
    int next,p;
    for(int i=1;i<n;i++)
    {
        next=a[i];
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            while(p<next)
            {
                cout<<p<<" "<<next<<'\n';
                if(s.empty())
                   break;
                p = s.top();
                s.pop();
            }
            if(p>next)
                s.push(p);

        }
        s.push(next);
    }
    while (!s.empty())
    {
        p = s.top();s.pop();
        next = -1;
        cout<<p<<" "<<next<<'\n';
    }
}
