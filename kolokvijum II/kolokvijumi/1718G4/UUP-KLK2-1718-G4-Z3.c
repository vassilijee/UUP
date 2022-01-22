#include <stdio.h>
#include <string.h>

/**
UUP-KLK2-1718-G4-Z3
Napisati program koji učitava string koji sadrži mala slova i crtice i od unetog stringa
pravi novi string u kom je svaki podstring između crtica zamenjen slovima koji se u podstringu
unetog stringa pojavljuju više od jednom (u bilo kom redosledu).

Primer: abba-afgf-ccc-fgh
Rezultat: ab-f-c
*/


int main() {
    // s1 nam je dat. s2 je novi string. token će imati reči između crtica, a pok_crtica će
    // pokazivati na poslednje unetu crticu (na početku je to početak stringa s2).
    char s1[100], s2[100], *token, *pok_crtica = s2;
    // i predstavlja indeks za s2. izmena predstavlja flag u odnosu na koji stavljamo ili ne stavljamo
    // novu crticu.
    char i = 0, izmena = 0;

    gets(s1);

    // Delimo stringove po crticama.
    token = strtok(s1, "-");
    while(token) {
        izmena = 0;
        // c nam je kopija tokena, pošto ćemo prolaziti slovo po slovo i upoređivati u odnosu na token.
        char *c = token;
        while (*c) {
            // Ako karakter nije prvo pojavljivanje tog slova u tokenu i ako se on već ne nalazi u našem novom stringu
            // nakon poslednje crtice, dodajemo ga u s2 i beležimo da se desila izmena.
            if (strchr(token, *c) != c && !strchr(pok_crtica, *c)) {
                s2[i++] = *c;
                izmena = 1;
            }
            // Prelazimo na sledeći karakter u tokenu.
            c++;
        }

        // Beležimo poslednju crticu u odnosu na koju ćemo proveravati da li smo
        // neki karakter već upisali u string.
        if (izmena) {
            s2[i++] = '-';
            pok_crtica = &s2[i-1];
        }
        // Prelazimo na sl. token.
        token = strtok(NULL, "-");
    }
    // Beležimo kraj stringa da ne bi ispisao čudne karaktere iz memorije i da bismo uklonili poslednju crticu.
    s2[strlen(s2)-1] = 0;
    printf(s2);

    return 0;
}
