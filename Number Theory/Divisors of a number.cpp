#include <bits/stdc++.h>
void printDivisors(int n)
{
    for (int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            if (n/i == i)
                printf("%d ", i);

            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
}
int main()
{
    printf("The divisors of 100 are: \n");
    printDivisors(100);
}
