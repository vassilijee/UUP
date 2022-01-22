#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fib(int n){

    if(n == 1 || n == 2)
        return 1;

    int prvi = 1, drugi = 1, treci;
    for(int i = 2; i<n; i++){
        treci = prvi+drugi;
        prvi = drugi;
        drugi = treci;
    }

    return treci;
}

double rek(int iteracija, int n, double gornji){

    if(n == iteracija)
        return fib(iteracija);

    if(iteracija%2 != 0)
        return fib(iteracija) + gornji/rek(iteracija+1, n, gornji-3);

    return fib(iteracija) - gornji/rek(iteracija+1, n, gornji-3);
}

double ite(int n){

    double gornji = 6, res = fib(n);

    for(int i = n-1; i>0; i--){
        if(i%2 != 0)
            res = fib(i) + gornji/res;
        else
            res = fib(i) - gornji/res;

        gornji+=3;
    }

    return res;
}

int main(){

    int n;
    scanf("%d", &n);

    printf("%lf\n%lf", rek(1, n, 3*n), ite(n));

    return 0;
}
