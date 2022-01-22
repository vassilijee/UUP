#include<stdio.h>

int main(){
    char c, proslo, cc;

    while((c = getchar()) != '\n'){
        cc = c;

        if(cc >= 'a' && cc <= 'z'){
            cc -= 32;
        }

        if(cc != proslo + 1) {
            printf("%c", c);
        }
        
        proslo = cc;
    }
    printf("\n");
}