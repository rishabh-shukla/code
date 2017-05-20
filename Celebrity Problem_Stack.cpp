#include<iostream>
#include<stack>
using namespace std;
#define N 8
bool  MATRIX[N][N] = {{0, 0, 1, 0},
                      {0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 0, 1, 0}};

bool knows(int a, int b)
{
    return MATRIX[a][b];
}
int main()
{
    stack<int> s;
    for(int i=0;i<4;i++)
        s.push(i);
    int a=s.top();
    s.pop();
    int b=s.top();
    s.pop();
    while(s.size()>1)
    {
        if(knows(a,b))
        {
            a=s.top();
            s.pop();
        }
        else
        {
            b=s.top();
            s.pop();
        }
    }
    int c=s.top();
    s.pop();
    if(knows(c,a))
        c=a;
    if(knows(c,b))
        c=b;
    for (int i = 0; i < 4; i++)
    {
        if ( (i != c) &&
                (knows(c, i) || !knows(i, c)) )
            {
                cout<<"No Celebrity";
                break;
            }
    }

    cout<<c;



}
