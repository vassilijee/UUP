#include <stdio.h>

int getp(int i, int p)
{
    int a, len = 0, oldP = p;

    while (p > 0)
    {
        len++;
        p /= 10;
    }

    p = oldP;

    i = len - i % len + 1;

    while (i-- > 0)
    {
        a = p % 10;

        p /= 10;

        if (p == 0)
        {
            p = oldP;
        }
    }
    return a;
}

double fr(int i, int n, int p)
{
    if (i == n)
    {
        return getp(i, p);
    }

    return getp(i, p) + 1 / fr(i + 1, n, p);
}

int main()
{
    int n, p;

    scanf("%d%d", &n, &p);

    printf("r: %lf", fr(1, n, p));
}