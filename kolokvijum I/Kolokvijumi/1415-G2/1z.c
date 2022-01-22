#include <stdio.h>

int pom(int n, int t){
    int cif;

    while(n){
        if(n % 10 == t){
            return 1;
        }
        n /= 10;
    }
    return 0;
}

int main(){
    // int test = 123;
    // printf("%d", pom(test, 2));

    int n, m, t, res = 1;

    scanf("%d%d%d", &n, &m, &t);

    for(int i = n; i <= m; i++){
        if(pom(i, t)){
            res *= i;
        }
    }

    printf("%d", res);

    return 0;
}