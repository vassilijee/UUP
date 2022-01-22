#include <stdio.h>
#include <math.h>

double fr(int n, int i)
{
    if (i == n)
    {
        return n - i + 1;
    }

    if (i % 2)
    {
        return n - i + 1 + sqrt(1.0) / fr(n, i + 1);
    }
    else
        return n - i + 1 + sqrt(2.0) / fr(n, i + 1);
}

double fi(int n)
{
    double sum;

    for (int i = n; i > 0; i--)
    {
        if (i == n)
        {
            sum = n - i + 1;
            continue;
        }

        if (i % 2)
        {
            sum = (n - i + 1) + sqrt(1.0) / sum;
        }
        else
            sum = (n - i + 1) + sqrt(2.0) / sum;
    }
    return sum;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%lf\n", fr(n, 1));
    printf("%lf", fi(n));
}