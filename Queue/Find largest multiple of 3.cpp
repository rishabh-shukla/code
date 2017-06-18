#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int multiple3(int a[],int n)
{
    sort(a,a+n);
    queue<int> q0,q1,q2;
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(a[i]%3==0)
            q0.push(a[i]);
        else if(a[i]%3==1)
            q1.push(a[i]);
        else
            q2.push(a[i]);
    }
    if(sum%3==1)
    {
        if(!q1.empty())
            q1.pop();
        else
        {
            if(!q2.empty())
                q2.pop();
            else
                return 0;
            if(!q2.empty())
                q2.pop();
            else
                return 0;
        }
    }
    else if(sum%3==1)
    {
        if(!q2.empty())
            q2.pop();
        else
        {
            if(!q1.empty())
                q1.pop();
            else
                return 0;
            if(!q1.empty())
                q1.pop();
            else
                return 0;
        }
    }
    int b[n],top=0;
    while(!q0.empty())
        {
            b[top++]=q0.front();
            q0.pop();
        }
    while(!q1.empty())
        {
            b[top++]=q1.front();
            q1.pop();
        }
    while(!q2.empty())
        {
            b[top++]=q2.front();
            q2.pop();
        }
    for(i=top-1;i>=0;i--)
        cout<<b[i];
    return top;
}
int main()
{
    int a[]={8,1,7,6,0};
    int n=5;
    if(multiple3(a,n)==0)
        cout<<"Not possible\n";

}
