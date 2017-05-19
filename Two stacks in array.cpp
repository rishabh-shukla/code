#include<iostream>
using namespace std;
int a[15]={0};
int i=0,j=14;
void push1(int a[],int item)
{
    if(i<j)
        {
            a[i]=item;
            i++;
        }
        else cout<<"Overflow";
}
void push2(int a[],int item)
{
    if(j>i)
        {
            a[j]=item;
            j--;
        }
        else cout<<"Overflow";
}
int pop1(int a[])
{
        if(i>=0)
        {
            i--;
            int t=a[i];
            a[i++]=0;
            return t;
        }
        else cout<<"Underflow";
}
int pop2(int a[])
{
        if(j<=14)
        {
            j++;
            int t=a[j];
            a[j++]=0;
            return t;
        }
        else cout<<"Underflow";
}
void print(int a[])
{
    for(int i=0;i<15;i++)
        cout<<a[i]<<" ";
}
int main()
{
    push1(a,2);
    push1(a,3);
    push1(a,4);
    push1(a,5);
    push2(a,-1);
    push2(a,-4);
    push2(a,-5);
    print(a);
    cout<<'\n';
    cout<<pop1(a);
    cout<<pop2(a);
    cout<<'\n';
    print(a);

}
