#include<stdio.h>
#include<math.h>

double fr(int i, int n, int p) {
	if(i == n) {
		return sqrt(p);
	}else {
		i++;

		if(i % 2) {
			return sqrt(p - fr(i, n, p + i));
		}else {
			return sqrt(p + fr(i, n, p + i));
		}
	}
}

double fi(int n) {
	int i, p = 0;
	double sum;

	for(i = 1; i <= n; p += i++);

	for(i = n; i > 0; i--) {
		if(i == n) {
			sum = sqrt(p);
		}else {
			if(i % 2) {
				sum = sqrt(p + sum);
			}else {
				sum = sqrt(p - sum);
			}
		}

		p -= i;
	}

	return sum;
}

int main(){
    int n;

    scanf("%d", &n);

    printf("r: %lf\n", fr(1, n, 1));
    printf("i: %lf", fi(n));
}
