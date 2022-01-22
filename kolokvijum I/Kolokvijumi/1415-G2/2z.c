#include <stdio.h>


int main(){
    char c, proslo = '\0';

    while((c = getchar()) != '\n'){
        
        if(c == proslo + 1 || c == proslo + 33)
            c -= 32;
        printf("%c", c);
        proslo = c;
        
    }
    return 0;
}