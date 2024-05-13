//E - Take

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_fill_take(const int *a, int n, int *b) {
	int result = 0;
	for(int i = 0; i < n; i++) {
		b[result++] = a[i];
	}
	return result;
}

int ints_take(const int *a, int n, int *b, int x) {
	int result = 0;
	if(x > 0 && x < n) {
		result = ints_fill_take(a,x,b);
	}
	else if(x >= n) {
		result = ints_fill_take(a,n,b);
	}
	else {
		result = 0;
	}
	return result;
}

void test(void){
	int a[1000];
    int n = ints_get_until(-1,a);
    int b[1000];
    int x;
    while(scanf("%d", &x) != EOF) {
    	int m = ints_take(a,n,b,x);
    	ints_println_special(b,m);
    }
}

void unit_test() {
    int a1[5] = {1,2,3,4,5};
    int b1[5];
    assert(ints_take(a1, 4, b1, -1) == 0);
	assert(ints_take(a1, 2, b1, 3) == 2 && b1[0] == 1 && b1[1] == 2);
	assert(ints_take(a1, 4, b1, 3) == 3 && b1[0] == 1 && b1[1] == 2);
	assert(ints_take(a1, 3, b1, 6) == 3 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3);
}

int main(void) {
	unit_test();
	test();
	return 0;
}