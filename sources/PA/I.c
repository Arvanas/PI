//I - Unaccumulate

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_unaccumulate (const int *a, int n, int *b) {
    int result = 0;
    if (a[0] != 0) {
        result = 0;
    }
    else {
        for(int i = 1; i < n; i++) {
            b[result++] = a[i] - a[i-1];
        }
    }
    return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int b[1000];
	int m = ints_unaccumulate(a,n,b);
	ints_println_special(b,m);
}

void unit_test() {
	int a1[10] = {0,5,6,10,11,14,18};
	int b1[10];
	assert(ints_unaccumulate(a1, 0, b1) == 0);
	assert(ints_unaccumulate(a1, 5, b1) == 4 && b1[0] == 5 && b1[1] == 1 && b1[2] == 4 && b1[3] == 1);
	assert(ints_unaccumulate(a1, 3, b1) == 2 && b1[0] == 5 && b1[1] == 1);
	assert(ints_unaccumulate(a1, 4, b1) == 3 && b1[0] == 5 && b1[1] == 1 && b1[2] == 4);
}

int main(void) {
	unit_test();
	test();
	return 0;
}