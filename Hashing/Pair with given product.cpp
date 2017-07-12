#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int a[]={10,20,9,40};
    int n=4;
    int prod=400;
    unordered_set<int> s;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            if(prod==0)
                cout<<"Yes\n";
            else continue;
        }
        if(prod%a[i]==0)
        {
            if(s.find(prod/a[i])!=s.end())
                cout<<"Yes\n";
            s.insert(a[i]);
        }
    }

}
