#include<stdio.h>
#include<string.h>

/**
UUP-KLK2-2018-G2-Z3
3 (7p). Napisati program koji menja unetu rečenicu koja se čuva kao string tako što iz reči koje se nalaze
u pravilno zatvorenim navodnicima (navodnici se nalaze i pre i posle reči) izbacuje sve suglasnike i same
navodnike oko te reči. Pretpostavlja se da se unose velika i mala slova, znak razmaka i navodnici pre i/ili
posle reči (navodnici se ne nalaze u samoj reči).

Primer: "Danas je "pravi" dan "za" sneg"
Ispis: "Danas je ai dan a sneg"
*/


int main() {
    char s[100];
    int n, i, j, pocetak = 0, m = 0;

    gets(s);

    n = strlen(s);
    for(i = 0; i < n; i++) {
        // Ako je sledeći karakter razmak ili kraj stringa:
        if (s[i+1] == ' ' || s[i+1] == '\0') {
            // Ako je početak (prvi karakter reči) jednak navodnicima:
            if (s[pocetak] == '"' && s[i] == '"') {
                // Upisujemo u naš string samo samoglasnike, ali po novoj dužini - m.
                for (j = pocetak + 1; j < i; j++)
                    if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
                        s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                    s[m++] = s[j];

                // Dodamo razmak.
                s[m++] = ' ';
            }
            // A ako početak nije samoglasnik, samo upišemo celu reč.
            else
                for (j = pocetak; j <= i + 1; j++)
                    s[m++] = s[j];

            pocetak = i + 2;
        }
    }

    s[m] = '\0';
    puts(s);

    return 0;
}
