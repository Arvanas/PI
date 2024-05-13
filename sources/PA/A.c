//A - Greather Than

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_greater_than(const int*a, int n, int* b, int x) {
	int result = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > x) {
			b[result++] = a[i];
		}
	}
	return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int b[1000];
	int x;
	while(scanf("%d", &x) != EOF) {
		int z = ints_greater_than(a,n,b,x);
		ints_println_special(b,z);
	}
}

void unit_test(void) {
	int a1[10] = {1,2,3,4,5,6,7,8,9,10};
	int b1[10];
	assert(ints_greater_than(a1,10,b1,5) == 5 && b1[0] == 6 && b1[1] == 7 && b1[2] == 8 && b1[3] == 9 && b1[4] == 10);
	assert(ints_greater_than(a1,10,b1,8) == 2 && b1[0] == 9 && b1[1] == 10);
	assert(ints_greater_than(a1,10,b1,9) == 1 && b1[0] == 10);
	assert(ints_greater_than(a1,10,b1,6) == 4 && b1[0] == 7 && b1[1] == 8 && b1[2] == 9 && b1[3] == 10);
}

int main(void) {
	unit_test();
	test();
	return 0;
}