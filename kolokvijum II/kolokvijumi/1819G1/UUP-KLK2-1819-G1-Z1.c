#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
UUP-KLK2-1819-G1-Z1
1 (6p). Napisati dve funkcije koje izračunavaju sledede razlomke, jedna iterativno a drugo rekurzivno za
dato N. Brojioci u razlomku su formirani kao niz prvih n prostih brojeva.
N = 7

G+2/
    (F-3/
        (E+5/
            (D-7/
                (C+11/
                    (B-13/
                        A)))))
= 71.028589
*/


int prost(int n) {
    // Brojač služi da bismo brojili do kog prostog broja smo stigli.
    int brojac = 0, prost;

    // Prolazimo kroz brojeve.
    for(int i = 2;;i++) {
        // Pretpostavimo da je i prost.
        prost = 1;
        // Proverimo da li je prost.
        for(int j = 2; j < i; j++)
            if (i%j == 0) {
                // Ako nije, menjamo flag.
                prost = 0;
                break;
            }

        // Ako nismo promenili flag znači da je prost, tada povećavamo brojač.
        if (prost) {
            brojac++;
            // Ako je to n-ti prost broj, vraćamo ga, ako ne, nastavljamo dalje kroz petlju.
            if (brojac == n)
                return i;
        }
    }
}

double rek(int n, int i) {
    // Ako smo došli do kraja izraza vraćamo samo kraj, odnosno slovo A.
    if (n == 1)
        return 'A';

    // Ako nismo računamo koje je slovo u pitanju - 'A'+n-1,
    // određujemo znak - pow(-1, i+1),
    // nađemo i-ti prost broj - prost(i)
    // i zovemo opet rekurzivno funkciju da bi izračunala isto to za imenilac.
    return 'A'+n-1 + pow(-1, i+1) * prost(i)/rek(--n, ++i);
}


double iter(int n) {
    double resenje = 'A';

    // Isto kao kod rekurzije, samo što idemo od nazad, odnosno od slova A,
    // tako da će svaki imenilac ulaziti u veći imenilac dok ne dođemo do vrha.
    for(int i = n-1; i > 0; i--)
        resenje = 'A'+n-i + pow(-1, i+1) * prost(i)/resenje;

    return resenje;
}


int main() {
    int n;
    scanf("%d", &n);
    printf("Rekurzija: %lf\n", rek(n, 1));
    printf("Iteracija: %lf\n", iter(n));

    return 0;
}
