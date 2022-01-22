#include <stdio.h>

/**
UUP-KLK2-1920-G1-Z2
2. (7p) Napisati program koja za unete brojeve n i m formira matricu kao u primeru. Matrica
treba da bude dimenzija m x m, popunjava se spiralno, sa početkom u gornjem levom
uglu. Prva vrednost koja se upisuje u matricu je broj n. Kada se dođe do ivice matrice,
prelazi se na naredni veći broj. Posle 9 se prelazi na 0. 0 ≤ n ≤ 9, 0 ≤ m ≤ 9
n=3 m=5
3 3 3 3 4
7 7 7 8 4
6 1 2 8 4
6 0 9 9 4
6 5 5 5 5
*/


// Proverava da li su koordinate i (vrsta) i j (kolona)
// unutar granica matrice (n i m).
int validneKoordinate(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
    int a[100][100];

    int i, j, m, n;

    // Promenljiva koja definiše smer kretanja. Pomeraji za svaki smer definisani su u
    // posebnim nizovima ispod
    int smer = 0;
    // Definišemo nizove koji predstavljaju pomeraje po x i po y.
    // Smerovi su 0: desno, 1: dole, 2: levo, 3: gore.
    // Pomeraji se dodaju na koordinate i i j
    // (i se krece po y-osi, j se krece po x-osi).
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};

    // Učitavamo dimenziju matrice
    scanf("%d%d", &n, &m);

    // Inicijalizujemo celu matricu na 0 (prazno polje).
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            a[i][j] = 0;
    // Broj koji upisujemo u polje i, j (prvi broj je 1).
    int br = n;
    // Krećemo od gornjeg levog ugla (0,0).
    i = j = 0;
    int brojac = 1;
    // Popunjavaćemo matricu sve dok se ne popune sva polja (m*m).
    while(brojac <= m * m) {
        brojac++;
        // Određujemo koje su potencijalne nove koordinate
        // tako što dodajemo pomeraje iz trenutnog smera.
        // Npr. ako je smer 0 (desno), i ostaje isto a j se povecava za 1.
        int ii = i + y[smer], jj = j + x[smer];

        // Odrediti sledeće polje za upisivanje
        // ako su validne koordinate iz trenutnog smera
        // i ako je prvo sledeće polje prazno.
        if (validneKoordinate(ii, jj, m, m) && a[ii][jj] == 0) {
            // U trenutno polje upisujemo trenutni broj.
            a[i][j] = br;
            // Postavljamo nove vrednosti
            // koordinata i prelazimo na sledeću iteraciju.
            i = ii;
            j = jj;
            continue;
        }
        // Ako sl. koordinate nisu u matrici povecavamo brojac.
        br = (br+1)%10;
        a[i][j] = br;
        // Ako prethodni uslov nije bio ispunjen, treba promeniti smer.
        // Kada smer dođe do 4, %4 ga resetuje na 0.
        // Ažuriramo koordinate sa novim smerom.
        smer = (smer + 1) % 4;
        i = i + y[smer];
        j = j + x[smer];
    }

    // Ispisujemo generisanu matricu.
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);

        putchar('\n');
    }

    return 0;
}
