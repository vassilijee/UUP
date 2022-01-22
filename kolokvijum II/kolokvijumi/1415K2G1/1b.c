#include <stdio.h>
#include <math.h>

double fr(int n, int i)
{
    if (i == n)
    {
        return sqrt((i / 2 + i % 2));
    }
    return sqrt((i / 2 + i % 2) + fr(n, i + 1));
}

double fi(int n)
{
    int i;
    double sum = 0.0;

    for (i = n; i > 0; i--)
    {
        if (i == n)
        {
            sum += sqrt(i / 2 + i % 2);
        }
        else
            sum = sqrt(sum + (i / 2 + i % 2));
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));
}