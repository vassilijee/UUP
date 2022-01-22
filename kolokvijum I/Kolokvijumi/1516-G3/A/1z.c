#include <stdio.h>
#include <math.h>

int reverse(int n)
{
    int temp = 0;
    while (n > 0)
    {
        temp = temp * 10 + n % 10;
        n = n / 10;
    }
    return temp;
}

int brojCifara(int n)
{
    int cif, i = 0;

    while (n)
    {
        n /= 10;
        i++;
    }
    return i;
}

int pom(int n)
{
    int cifre = pow(10, brojCifara(n) - 1), prva, poslednja;
    prva = n / cifre;
    poslednja = n % 10;

    int cif, novi;

    while (n)
    {
        cif = n % 10;
        if (cif != prva && cif != poslednja)
        {
            novi *= 10;
            novi += cif;
        }
        n /= 10;
    }
    return reverse(novi);
}

int main()
{
    int m, sum = 0;

    while (1)
    {
        scanf("\n%d", &m);
        if (m == 0)
        {
            break;
        }
        sum += pom(m);
    }

    printf("\n%d", sum);

    return 0;
}
