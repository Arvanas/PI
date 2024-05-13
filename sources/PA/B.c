//B - Less Than

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_less_than(const int*a, int n, int* b, int x) {
	int result = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] < x) {
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
		int z = ints_less_than(a,n,b,x);
		ints_println_special(b,z);
	}
}

void unit_test() {
    int a1[10] = {1,2,3,4,5,6,7,8,9,10};
    int b1[10];
    assert(ints_less_than(a1,10,b1,2) == 1 && b1[0] == 1);
    assert(ints_less_than(a1,10,b1,3) == 2 && b1[0] == 1 && b1[1] == 2);
    assert(ints_less_than(a1,10,b1,4) == 3 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3);
    assert(ints_less_than(a1,10,b1,5) == 4 && b1[0] == 1 && b1[1] == 2 && b1[2] == 3 && b1[3] == 4);
}

int main(void) {
	unit_test();
	test();
	return 0;
}