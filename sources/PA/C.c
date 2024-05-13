//C - Digits Sum

#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

const char *author = "Tomás Arvanas";

int digits(int x) {
	return x < 10 ? x : digits(x/10) + x % 10;
}

int digits_sum(const int *a, int n, int *b) {
	int result = 0;
	for(int i = 0; i < n; i++) {
		b[result++] = digits(a[i]);
	}
	return result;
}

 void test(void) {
 	int a[1000];
 	int n = ints_get_until(-1,a);
 	int b[1000];
 	int m = digits_sum(a,n,b);
 	ints_println_special(b,m);
 }

 void unit_test(void){
 	int a1[5] = {113,278,33,40,523};
 	int b1[5];
 	assert(digits_sum(a1,1,b1) == 1 && b1[0] == 5);
 	assert(digits_sum(a1,2,b1) == 2 && b1[0] == 5 && b1[1] == 17);
 	assert(digits_sum(a1,3,b1) == 3 && b1[0] == 5 && b1[1] == 17 && b1[2] == 6);
 	assert(digits_sum(a1,4,b1) == 4 && b1[0] == 5 && b1[1] == 17 && b1[2] == 6 && b1[3] == 4);
 }

 int main(void) {
 	unit_test();
 	test();
 	return 0;
 }