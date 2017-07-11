# include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
void printGrouped(string str)
{
    int n = str.length();
    int  count[MAX_CHAR] = {0};
    for (int i = 0 ; i < n ; i++)
        count[str[i]-'a']++;
    for (int i = 0; i < n ; i++)
    {
        while (count[str[i]-'a']--)
            cout << str[i];
        count[str[i]-'a'] = 0;
    }
}
int main()
{
    string str = "geeksforgeeks";

    printGrouped(str);

    return 0;
}
