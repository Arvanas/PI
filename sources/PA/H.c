//H - Accumulate

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_accumulate(const int *a, int n, int *b) {
	int result = 0;
	for(int i = 0; i <= n; i++) {
		b[result++] = ints_sum(a,i);
	}
	return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int b[1000];
	int m = ints_accumulate(a,n,b);
	ints_println_special(b,m);
}

void unit_test(void) {
	int a1[4] = {1,2,3,4};
	int b1[5];
	assert(ints_accumulate(a1,1,b1) == 2 && b1[0] == 0 && b1[1] == 1);
	assert(ints_accumulate(a1,2,b1) == 3 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3);
	assert(ints_accumulate(a1,3,b1) == 4 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6);
	assert(ints_accumulate(a1,4,b1) == 5 && b1[0] == 0 && b1[1] == 1 && b1[2] == 3 && b1[3] == 6 && b1[4] == 10);

}

int main(void) {
	unit_test();
	test();
	return 0;
}