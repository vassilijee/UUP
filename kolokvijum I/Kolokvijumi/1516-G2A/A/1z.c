#include<stdio.h>
int pom(int arg)
{
    int cif, obrnuti, copy = arg;

    while(arg){
        cif = arg % 10;
        obrnuti = obrnuti * 10 + cif;
        arg /= 10;
    }

    return copy > obrnuti;
}

int main()
{
    // int test = 123;

    // printf("%d", pom(test));
    int m, i, sum = 0;

    while(1)
    {
        scanf("%d", &m);
        if(m == 0)
        {
            break;
        }
        sum += pom(m) * m;
    }

    printf("%d", sum);
}