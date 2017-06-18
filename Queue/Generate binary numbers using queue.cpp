// C++ program to generate binary numbers from 1 to n
#include <iostream>
#include <queue>
using namespace std;
void generatePrintBinary(int n)
{
    queue<string> q;
    q.push("1");
    while (n--)
    {
        string s1 = q.front();
        q.pop();
        cout << s1 << "\n";
        string s2 = s1;  // Store s1 before changing it
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}
int main()
{
    int n = 10;
    generatePrintBinary(n);
    return 0;
}
