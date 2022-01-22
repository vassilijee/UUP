#include <stdio.h>
#include <math.h>

double fi(int n)
{
    double sum = 0.0;
    int i;

    for (i = n; i > 0; i--)
    {
        if (i % 2)
        {
            sum = sqrt(1.0 / (n - i + 1) + sum);
        }
        else
        {
            sum = sqrt(2.0 / (n - i + 1) + sum);
        }
    }
    return sum;
}

double fr(int n, int i)
{
    if (i == n)
    {
        if (i % 2)
        {
            return sqrt(1.0 / (n - i + 1));
        }
        else
        {
            return sqrt(2.0 / (n - i + 1));
        }
    }

    if (i % 2)
    {
        return sqrt(1.0 / (n - i + 1) + fr(n, i + 1));
    }
    else
    {
        return sqrt(2.0 / (n - i + 1) + fr(n, i + 1));
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));
}