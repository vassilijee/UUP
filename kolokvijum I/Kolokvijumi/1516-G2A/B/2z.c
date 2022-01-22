#include <stdio.h>

int main()
{
    char c, slovo;
    int j;

    while ((c = getchar()) != '\n')
    {
        if (c >= 'a' && c <= 'z')
        {
            slovo = c;
            j = 0;
        }
        else if (c >= '0' && c <= '9')
        {
            j *= 10;
            j += c - '0';
        }
        else
        {
            while (j-- > 0)
            {
                printf("%c", slovo);
            }
            printf("%c", c);
        }
    }
    return 0;
}
