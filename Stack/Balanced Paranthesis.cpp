#include<iostream>
#include<stack>
using namespace std;
bool isMatchingPair(char character1, char character2)
{
   if (character1 == '(' && character2 == ')')
     return 1;
   else if (character1 == '{' && character2 == '}')
     return 1;
   else if (character1 == '[' && character2 == ']')
     return 1;
   else
     return 0;
}
int main()
{
    stack<char> s;
    char c[]="({})[]";
    int i=0;
    while(c[i])
    {
        if(c[i]=='{' || c[i]=='(' || c[i]=='[')
            s.push(c[i]);
        if(c[i]=='}' || c[i]==')' || c[i]==']')
        {
            if(s.empty())
                {
                    cout<<"NO1";
                    return 0;
                }
            else if(!isMatchingPair(s.top(),c[i]))
                {
                    cout<<"NO2";
                    return 0;
                }
                s.pop();
        }
        i++;
    }
    if(s.empty())
        cout<<"YES";
    else cout<<"NO3";
}
