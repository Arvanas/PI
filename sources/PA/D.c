//D - Append

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_append(const int *a, int n, const int *b, int m, int *c) {
	int result = 0;
	for(int i = 0; i < n + m; i++) {
		if(i < n) {
			c[result++] = a[i];
		}
		else{
			c[result++] = b[i - n];
		}
	}
	return result;
}

void test(void) {
	int a[1000];
    int n = ints_get_until(-1,a);
    int b[1000];
    int m = ints_get_until(-1,b);
    int c[2000];
    int z = ints_append(a,n,b,m,c);
    ints_println_special(c, z);
    int w = ints_append(b,m,a,n,c);
    ints_println_special(c,w);
}

void unit_test()
{
    int a1[5] = {1,2,3,4,5};
    int b1[5] = {1,2,3,4,5};
    int c1[10];
    assert(ints_append(a1, 1, b1, 1, c1) == 2 && c1[0] == 1 && c1[1] == 1);
	assert(ints_append(a1, 2, b1, 2, c1) == 4 && c1[0] == 1 && c1[1] == 2 && c1[2] == 1 && c1[3] == 2);
	assert(ints_append(b1, 1, a1, 2, c1) == 3 && c1[0] == 1 && c1[1] == 1 && c1[2] == 2);
	assert(ints_append(b1, 2, a1, 3, c1) == 5 && c1[0] == 1 && c1[1] == 2 && c1[2] == 1 && c1[3] == 2 && c1[4] == 3);
}

int main(void) {
	unit_test();
	test();
	return 0;
}