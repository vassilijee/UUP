#include<stdio.h>
#include<math.h>

double fr(int n, int i)
{
    int a;

    if(i % 2)
        a = 1;
    else
        a = n;

    if(i == n)
        return sqrt(a);

    return sqrt(a + fr(n, i + 1));
}

double fi(int n){
    double sum;
    int a;

    for(int i = n; i > 0; i--){
        if(i % 2)
            a = 1;
        else
            a = n;

        if(i == n)
            sum = sqrt(a);
        else
            sum = sqrt(a + sum);
    }
    return sum;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));
}
