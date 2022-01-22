#include <stdio.h>

int obrnuti(int n)
{
    int temp = 0;

    while (n)
    {
        temp = temp * 10 + n % 10;
        n /= 10;
    }
    return temp;
}

int test(int n)
{
    int cif = 0, novi = 0;

    while (n)
    {
        cif = n % 10;
        if (cif % 2 == 0)
        {
            novi *= 10;
            novi += cif;
        }
        n /= 10;
    }
    return obrnuti(novi);
}

int main()
{
    int a, sum = 0;

    while (1)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            break;
        }
        sum += test(a);
    }
    printf("%d", sum);
}
