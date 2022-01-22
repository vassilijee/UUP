#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//3
//5 3 6
//3 5 1
//2 1 3

int main(){

    int n;
    scanf("%d", &n);

    int mat_a[n+2][n+2];
    for(int i = 0; i<=n+1; i++){
        for(int j = 0; j<=n+1; j++){
            mat_a[i][j] = 0;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            scanf("%d", &mat_a[i][j]);
        }
    }

    int mat_b[n][n];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            mat_b[i-1][j-1] = mat_a[i-1][j] + mat_a[i+1][j] + mat_a[i][j+1] + mat_a[i][j-1] - mat_a[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%-3d ", mat_b[i][j]);
        }
        printf("\n");
    }

    return 0;
}
