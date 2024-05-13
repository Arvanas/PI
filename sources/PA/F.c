//F - Drop

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_fill_drop(const int *a, int n, int *b, int x) {
	int result = 0;
	for(int i = x; i < n; i++) {
		b[result++] = a[i];
	}
	return result;
}

int ints_drop(const int *a, int n, int *b, int x) {
	int result = 0;
	if(x >= 0 && x < n) {
		result = ints_fill_drop(a,n,b,x);
	}
	else if(x < 0) {
		result = ints_fill_drop(a,n,b,0);
	}
	else{
		result = 0;
	}
	return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int b[1000];
	int x;
	while(scanf("%d", &x) != EOF) {
		int m = ints_drop(a,n,b,x);
		ints_println_special(b,m);
	}
}

void unit_test(void) {
    int a1[5] = {1,2,3,4,5};
    int b1[5];
    assert(ints_drop(a1, 5, b1, -1) == 5 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3 && b1[3] == 4 && b1[4] == 5);
	assert(ints_drop(a1, 5, b1, 4) == 1 && b1[0] == 5);
	assert(ints_drop(a1, 5, b1, 6) == 0);
	assert(ints_drop(a1, 0, b1, 0) == 0);
}

int main(void) {
	unit_test();
	test();
	return 0;
}