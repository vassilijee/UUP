#include <stdio.h>

int main()
{
    char c, cifara;
    int broj = 0;

    while ((c = getchar()) != '\n')
    {
        if (c >= '1' && c <= '9')
        {
            if (cifara < 3)
            {
                cifara++;
                broj *= 10;
                broj += c - '0';
            }
            else
            {
                broj = broj % 100;
                broj *= 10;
                broj += c - '0';
            }
        }
    }
    printf("%d", broj);
}
