#include <stdio.h>
#include <math.h>

int getP(int p, int i)
{ // NE ZNAM JEL DOBAR
    int len = 0, pp = p;

    while (p > 0)
    {
        len++;
        p /= 10;
    }

    int a[len], index, broj;

    p = pp;

    if (i > len)
    {
        index = len - i % len;
    }
    else
        index = i;

    for (i = len - 1; i >= 0; i--)
    {
        a[i] = p % 10;
        p /= 10;
    }

    broj = a[index];

    return broj;
}

double fr(int n, int i, int p)
{
    if (i == n)
        return getP(p, i);

    return getP(p, i) + 1 / fr(n, i + 1, p);
}

//double fi(int n)
//{
//    double sum = 0.0;
//    int i;
//
//    for(i = n; i > 0; i--){
//        if(i == n){
//            sum = sqrt((2 * n - 1) * (n - i + 1));
//        }
//        else sum = sqrt((2 * i - 1) * (n - i + 1) + sum);
//    }
//    return sum;
//}

int main()
{
    int n, p, a;
    scanf("%d%d", &n, &p);

    printf("%d", a);
    printf("r: %lf\n", fr(n, 0, p));
    //    printf("i: %lf", fi(n));

    return 0;
}
