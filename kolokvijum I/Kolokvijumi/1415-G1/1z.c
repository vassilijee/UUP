#include<stdio.h>

int pom(int n){
    int cif, veci = 0;
    while(n){
        cif = n % 10;
        if(cif >= 5)
            veci = 1;
        n /= 10;
    }
    return (veci == 0) ? 1 : 0;
}



int main(){
///    int a = 1236, b = 123;
///    printf("%d %d", pom(a), pom(b));

    int n, m, suma = 0;

    scanf("%d%d", &n, &m);

    for(int i = n; i <= m; i++){
        if(pom(i)){
            suma += i;
        }
    }
    printf("%d", suma);
}
// int main() {
// 	int min, max, sum = 0;

// 	scanf("%d%d", &min, &max);

// 	while(min++ <= max) {
// 		sum += pom(min) * min;
// 	}

// 	printf("%d\n", sum);

// 	return 0;	
// }