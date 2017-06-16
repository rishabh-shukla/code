#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int a[]={11,13,21,3};
    int n=4;
    int next,item,i=0;
    stack<int> s;
    s.push(a[0]);
    for(i=1;i<n;i++)
    {
        next=a[i];
        if(!s.empty())
            {
                item=s.top();
                s.pop();
                while(item<next)
                {
                    cout<<item<<" -> "<<next<<'\n';
                    if(s.empty())
                       break;
                    item=s.top();
                    s.pop();
                }
                if(item>next)
                    s.push(item);
            }
        s.push(next);
    }
    while(!s.empty())
    {
        item=s.top();
        s.pop();
        next=-1;
        cout<<item<<" -> "<<next<<'\n';
    }
}
