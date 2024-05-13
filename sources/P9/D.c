//D - 

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

int ints_max(const int *a, int n) {
    int result = a[0];
    for(int i = 1; i < n; i++)
    	if(result < a[i])
    		result = a[i];
    return result;	
}

int ints_argsmax(const int *a, int n, int *b) {
    int result = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == ints_max(a, n)){
            b[result++] = i;
        }
    }
    
    return result;
}

void unit_test(void) {
    int a1[10] = {1,2,4,7,6,7,7,4,2,1};
    int b1[10] = {};
    assert(ints_argsmax(a1,4,b1) == 1);
    assert(ints_argsmax(a1,6,b1) == 2);
    assert(ints_argsmax(a1,9,b1) == 3);
}

void test(void) {
    int a[1000];
    int n = ints_get(a);
    int b[1000];
    int m = ints_argsmax(a,n,b);
    printf("%d ", m);
    ints_println_basic(b,m);
}


int main(void) {
    unit_test();
    test();
    return 0;
}