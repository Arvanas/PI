//G - Ascending

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_ascending(const int *a, int n, int *b) {
	b[0] = a[0];
	int result = 1;
	if(n <= 0) {
		result = 0;
	}
	else {
		for(int i = 1; i < n; i++) {
			if(a[i] >= ints_max(a,i)) {
				b[result++] = a[i];
			}
		}
	}
	return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int b[1000];
	int m = ints_ascending(a,n,b);
	ints_println_special(b,m);
}

void unit_test(void) {
	int a1[5] = {2,3,3,1,4};
	int b1[5];
	assert(ints_ascending(a1,2,b1) == 2 && b1[0] == 2 && b1[1] == 3);
	assert(ints_ascending(a1,3,b1) == 3 && b1[0] == 2 && b1[1] == 3 && b1[2] == 3);
	assert(ints_ascending(a1,4,b1) == 3 && b1[0] == 2 && b1[1] == 3 && b1[2] == 3);
	assert(ints_ascending(a1,5,b1) == 4 && b1[0] == 2 && b1[1] == 3 && b1[2] == 3 && b1[3] == 4);
}

int main(void) {
	unit_test();
	test();
	return 0;
}