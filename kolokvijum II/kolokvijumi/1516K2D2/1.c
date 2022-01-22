#include <stdio.h>
#include <math.h>

double fr(int n, int i)
{
    if (i == n)
        return sqrt((2 * n - 1) * (n - i + 1));

    return sqrt((2 * i - 1) * (n - i + 1) + fr(n, i + 1));
}

double fi(int n)
{
    double sum = 0.0;
    int i;

    for (i = n; i > 0; i--)
    {
        if (i == n)
        {
            sum = sqrt((2 * n - 1) * (n - i + 1));
        }
        else
            sum = sqrt((2 * i - 1) * (n - i + 1) + sum);
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));

    return 0;
}
