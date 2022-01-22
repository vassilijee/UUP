#include <stdio.h>

double fr(int n, int i)
{
    if (i == n)
    {
        return (i / 2 + i % 2);
    }
    return (i / 2 + i % 2) + 1 / fr(n, i + 1);
}

double fi(int n)
{
    int i;
    double sum = 0.0;

    for (i = n; i > 0; i--)
    {
        if (i == n)
        {
            sum += (i / 2 + i % 2);
        }
        else
        {
            sum = 1 / sum + (i / 2 + i % 2);
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));
}