#include <stdio.h>
#include <math.h>

double fr(int n, int i, int p)
{
    if (i == 1)
    {
        if (n % 2)
            p = n / 2;
    }

    if (--p <= 0)
        p = n / 2;

    if (i == n)
        return sqrt(i * p);

    return sqrt(i * p + fr(n, i + 1, p));
}

double fi(int n)
{
    double sum;
    int p = 0;

    for (int i = n; i > 0; i--)
    {
        if (++p > n / 2)
        {
            p = 1;
        }
        sum = sqrt(i * p + sum);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1, 0));
    printf("r: %lf\n", fi(n));
}