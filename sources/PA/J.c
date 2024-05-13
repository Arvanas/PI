//I - Unaccumulate

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int ints_find_triple(const int *a, int n) {
	int result = -1;
	for(int i = n; i >= 0; i--) {
		if(a[i] == a[i+1] && a[i] == a[i+2]) {
			result = i;
		}
	}
	return result;
}

void test(void) {
	int a[1000];
	int n = ints_get_until(-1,a);
	int m = ints_find_triple(a,n);
	printf("%d\n", m);
}


void unit_test(void) {
	int a1[14] = {1,2,3,3,3,4,5,5,5,6,7,7,7,8};
	assert(ints_find_triple(a1, 1) == -1);
	assert(ints_find_triple(a1, 5) == 2);
	assert(ints_find_triple(a1, 10) == 2);
	assert(ints_find_triple(a1, 14) == 2);
}

int main(void){
	unit_test();
	test();
	return 0;
}