//C - Segundo Máximo

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

int ints_all_equal(const int *a, int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(a[0] == a[i]) {
            result++;
        }
    }
    if(result == n){
        return 1;
    }
    else{
        return 0;
    }
}

int ints_max(const int *a, double n) {
    int result = a[0];
    for(int i = 1; i < n; i++)
    	if(result < a[i])
    		result = a[i];
    return result;	
}

int arraywithoutmax(int *a, int n,int *b) {
	int result = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != ints_max(a,n) ){
			b[result++] = a[i];
		}
	}

	return result;
}

int ints_second_max(const int *b, int m) {
    int result = b[0];
    for(int i = 1; i < m; i++)
    	if(result < b[i])
    		result = b[i];
    return result;	
}


void unit_test(void) {
    int b1[10] = {1,3,5,7,8,3,5,1,8,2};
    assert(ints_second_max(b1,2) == 3);
    assert(ints_second_max(b1,4) == 7);
    assert(ints_second_max(b1,7) == 8);
    assert(ints_second_max(b1,10) == 8);
}

void test() {
	int a[1000];
    int n = ints_get(a);
    int b[1000];
    int m = arraywithoutmax(a,n,b);
    int z = ints_second_max(b,m);
    if(ints_all_equal(a,n) == 0){
        printf("%d\n", z);
    }
    else{
        printf("Pre-condicao: o array tem que ter pelo menos dois elementos com valores diferentes!");
    }
}

int main(void) {
	unit_test();
	test();
	return 0;
}