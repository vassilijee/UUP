#include<stdio.h>

int main()
{
    char c;

    int j = 0;

    while((c = getchar()) != '\n')
    {
        if(c >= '0' && c <= '9')
        {
            j *= 10;
			j += c - '0';
        }

        else
        {
            while(j-- > 0)
            {
                printf("%c", c);
            }
            j = 0;
        }
    }
}