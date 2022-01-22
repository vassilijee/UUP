#include <stdio.h>

double fr(int n, int i)
{
    if (i == n)
    {
        return i;
    }

    if (i % 2)
        return i + (n * 2 - 2 * (i - 1)) / fr(n, i + 1);
    else
        return i - (n * 2 - 2 * (i - 1)) / fr(n, i + 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf", fr(n, 1));
}