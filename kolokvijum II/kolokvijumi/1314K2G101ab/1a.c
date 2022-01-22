#include <stdio.h>

/// 1.	Iterativno i rekurzivno napisati funkciju koja izračunava sledeći razlomak
///     za uneto n. U primeru je n=6:

double fi(int n)
{
    int i, p = 0;
    double sum = 0.0;

    for (i = 1; i <= n; i++)
    {
        p += i;
    }

    for (i = n; i > 0; i--)
    {
        if (i != n)
        {
            p -= i + 1;

            if (!(i % 2))
                sum *= -1;

            sum = p + 1 / sum;
        }
        else
            sum = p;
    }
    return sum;
}

double fr(int i, int n, int p)
{
    double a;

    p += i;

    if (i > n)
    {
        return p;
    }

    a = 1 / fr(i + 1, n, p);

    if (!(i % 2))
    {
        a *= -1;
    }

    return p + a;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf \n", fr(1, n, 0));
    printf("i: %lf \n", fi(n));
}
