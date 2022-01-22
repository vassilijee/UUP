#include <stdio.h>

#define SIZE 100

int a[SIZE][SIZE];

void ispis(int n)
{
    int i, j;

    for (i = 0; i < n; i++, printf("\n"))
    {
        for (j = 0; j < n; j++)
        {
            printf("%2d", a[i][j]);
        }
    }
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < n - j)
            {
                a[i][j] = i + 1;
            }
            else
            {
                a[i][j] = n - j;
            }
        }
    }
    ispis(n);
    return 0;
}
