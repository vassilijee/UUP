#include<stdio.h>
#include<string.h>

/**
UUP-KLK2-1920-G1-Z3
3. (7p) Napisati program koji menja sve unete reči u unetom stringu tako da im mala slova
postanu velika ako su palindromi, ili ih obrće ako nisu palindromi. Palindrom je reč koja
se isto čita sa leva na desno i sa desna na levo. Pretpostavlja se da se unose samo
mala slova i znak razmaka.
Primer: ovo je palindrom za reper
Rezultat: OVO ej mordnilap az REPER
*/

/// Funkcija koja obrće deo stringa od pozicije x do pozicije y.
void obrni(char* s, int x, int y) {
    int i, j;
    for(i = x, j = y-1; i < j; i++, j--) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

/// Funkcija koja deo stringa od pozicije x do pozicije y pretvara u velika slova.
void velika(char* s, int x, int y) {
    int i, j;
    for(i = x; i <= y; i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
    }
}

/// Funkcija koja proverava da li je deo stringa od pozicije x do pozicije y palindom.
int palindrom(char* s, int x, int y) {
    int i, j;
    for(i = x, j = y-1; i < j; i++, j--) {
        if (s[i] != s[j])
            return 0;
    }

    return 1;
}

int main() {
    char s[100];
    int n, i, j, pocetak = 0;

    gets(s);

    n = strlen(s);
    for(i = 0; i <= n; i++){
    /// Kada je trenutni karakter spejs ili kraj stringa, znači da smo stigli do kraja reči.
        if (s[i] == ' ' || s[i] == '\0') {
            if (!palindrom(s, pocetak, i))
                /// Obrcemo reč - imamo njen kraj (trenutna pozicija) i početak (prethodno sačuvan u promenljivoj pocetak).
                obrni(s, pocetak, i);
            else
                velika(s, pocetak, i);

            /// Sledeća reč počinje sa karakterom posle spejsa, pa pamtimo njenu poziciju kao početak sledeće reči.
            pocetak = i+1;
        }
    }

    puts(s);

    return 0;
}
