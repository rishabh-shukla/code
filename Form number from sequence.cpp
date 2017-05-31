#include <iostream>
#include <string>
#include <stack>
using namespace std;
void PrintMinNumberForPattern(string seq)
{
    string result;
    stack<int> stk;

    for (int i = 0; i <= seq.length(); i++)
    {
        stk.push(i + 1);

        if (i == seq.length() || seq[i] == 'I')
        {
            while (!stk.empty())
            {
                int k=stk.top();
                result += k+'0';
                result += " ";
                stk.pop();
            }
        }
    }

    cout << result << endl;
}
int main()
{
    PrintMinNumberForPattern("IDID");
    PrintMinNumberForPattern("I");
    PrintMinNumberForPattern("DD");
    PrintMinNumberForPattern("II");
    PrintMinNumberForPattern("DIDI");
    PrintMinNumberForPattern("IIDDD");
    PrintMinNumberForPattern("DDIDDIID");
    return 0;
}
