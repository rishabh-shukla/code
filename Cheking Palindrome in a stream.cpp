#include<stdio.h>
#include<string.h>
#define d 256
#define q 103
void checkPalindromes(char str[])
{
    int N = strlen(str);
    printf("%c Yes\n", str[0]);
    if (N == 1) return;
    int firstr  = str[0] % q;
    int second = str[1] % q;

    int h = 1, i, j;
    for (i=1; i<N; i++)
    {
        if (firstr == second)
        {
            for (j = 0; j < i/2; j++)
            {
                if (str[j] != str[i-j])
                    break;
            }
            (j == i/2)?  printf("%c Yes\n", str[i]):
            printf("%c No\n", str[i]);
        }
        else printf("%c No\n", str[i]);
        if (i != N-1)
        {
            if (i%2 == 0)
            {
                h = (h*d) % q;
                firstr  = (firstr + h*str[i/2])%q;
                second = (second*d + str[i+1])%q;
            }
            else
            {
                second = (d*(second + q - str[(i+1)/2]*h)%q
                          + str[i+1])%q;
            }
        }
    }
}
int main()
{
    char *txt = "aabaacaabaa";
    checkPalindromes(txt);
    getchar();
}
