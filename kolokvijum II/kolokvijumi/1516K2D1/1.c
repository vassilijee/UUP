#include <stdio.h>

double fr(int n, int i)
{
    if (n == i)
        return 2 * n - 1;
    return 2 * i - 1 + (n - i + 1) / fr(n, i + 1);
}

double fi(int n)
{
    double sum;

    for (int i = n; i > 0; i--)
    {
        if (i == n)
        {
            sum = 2 * i - 1;
        }
        else
        {
            sum = 2 * i - 1 + (n - i + 1) / sum;
        }
    }
    return sum;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf\n", fi(n));
}
