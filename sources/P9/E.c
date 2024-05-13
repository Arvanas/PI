//E - Soma de dois Arrays

#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = "Tomás Arvanas";

int ints_get(int *a) {
    int result = 0;
    int x;
    while(scanf("%d", &x) != EOF)
        a[result++] = x;
    return result;
}

void ints_println_basic(const int *a, int n) { //Escreve os valores de todos os elementos na mesma linha, com um espaço
	if(n > 0) {
		printf("%d", a[0]);
		for(int i = 1; i < n; i++)
			printf(" %d", a[i]);
	}
	printf("\n");
}

int mult_arrays(const int *a, int n, int *b) {
    int result = 0;
    for(int i = 0; i < n-1; i++) {
        b[result++] = a[i] * a[i+1];
    }
    b[result++] = a[n-1] * a[n-1];

    return result;
}

int sum_arrays(const int *a, const int *b, int m, int *c) {
    int result = 0;
    for(int i = 0; i < m; i++) {
        c[result++] = a[i] + b[i];
    }

    return result;
}

int somadoarray(const int *c, int w)
{
    int result=0;
    for(int i = 0; i < w; i++) {
        result+=c[i];
    }
    return result;
}

void unit_test(void) {
    int c1[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(somadoarray(c1,4) == 10);
    assert(somadoarray(c1,5) == 15);
    assert(somadoarray(c1,6) == 21);
    assert(somadoarray(c1,3) == 6);
}

void test(void) {
    int a[1000];
    int n = ints_get(a);
    int b[1000];
    int m = mult_arrays(a,n,b);
    int c[1000];
    int w = sum_arrays(a,b,m,c);
    printf("%d ", somadoarray(c,w));
    ints_println_basic(c,w);
}

int main(void) {
    unit_test();
    test();
    return 0;
}
