#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int a[]={10, 4, 5, 90, 120, 80};
    int n=6;
    stack<int> s;
    s.push(0);
    int S[n];
    S[0]=1;
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && a[s.top()]<=a[i])
            s.pop();
        S[i]=(s.empty())?(i+1):(i-s.top());
        s.push(i);
    }
    for(int i=0;i<n;i++)
        cout<<S[i]<<" ";
}
