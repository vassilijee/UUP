#include<stdio.h>

double fr(int n, int i){
    if(i == n){
        return n;
    }

    if(i % 2){
        return 1 + 1 / fr(n ,i + 1);
    }
    else return n + 1 / fr(n, i + 1);
}

double fi(int n){
    int a;
    double sum;

    for(int i = n; i > 0; i--){
        if(i % 2){
            a = 1;
        }
        else{
            a = n;
        }

        if(i == n){
            sum = a;
        }
        else{
            sum = a + 1 / sum;
        }
    }

    return sum;
}


int main(){
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(n, 1));
    printf("i: %lf", fi(n));
}
