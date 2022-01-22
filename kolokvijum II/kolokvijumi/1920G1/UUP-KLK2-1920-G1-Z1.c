#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
UUP-KLK2-1920-G1-Z1
*/

int brojilac(int n, int i) {
    return (i%2) ? i/2+1 : n-i/2+1;
}

double imenilac(int n, int i) {
    return (i%2) ? (n-i/2)*(n-i/2) : (i/2)*(i/2);
}

double rek(int n, int i) {
    if (i == n)
        return sqrt(brojilac(n, i)/imenilac(n, i));

    return sqrt(brojilac(n, i)/imenilac(n, i) + rek(n, ++i));
}

double iter(int n) {
    double suma = sqrt((double)brojilac(n, n)/imenilac(n, n));

    for (int i = n-1; i >= 1; i--) {
        suma = sqrt((double)brojilac(n, i)/imenilac(n, i) + suma);
    }

    return suma;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("Rekurzija: %lf\n", rek(n, 1));
    printf("Iteracija: %lf\n", iter(n));

    return 0;
}
