#include <stdio.h>
#include <stdlib.h>

char lower(char c){

    if(c>='A' && c <= 'Z')
        c += 'a' - 'A';

    return c;
}

int main(){

    char str[100];
    gets(str);

    int pocetak_reci = 0, kraj_reci;
    int i = 0;

    while(str[i] != '\0'){
        if(str[i+1] == ' ' || str[i+1] == '\0'){
            kraj_reci = i;
            int nova_rec;
            if(str[pocetak_reci] == '\"' && str[kraj_reci] == '\"'){
                int index = pocetak_reci;
                printf("%d %d", pocetak_reci, kraj_reci);
                for(int j = pocetak_reci+1; j<=kraj_reci; j++){
                    char low = lower(str[j]);
                    printf("%d\n", low);
                    if(low == 'a' || low == 'e' || low == 'i' || low == 'o' || low == 'u'){
                        str[index++] = str[j];
                    }
                }
                puts(str);
                nova_rec = index;
                for(int j = i+1; j<=strlen(str); j++){
                    str[index++] = str[j];
                }
                i = nova_rec;
            }
            pocetak_reci = i+2;
        }
        i++;
    }

    puts(str);
    return 0;
}
