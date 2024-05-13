// B - Combustível

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "our_ints.h"
#include "our_doubles.h"

const char *author = "Tomás Arvanas";

int gas(const double *a, int n, double *b, int m, double x, double *c) {
	int result = 0;

	for(int i = 0; i < n; i++) {
		c[result++] = (x / b[i]) - (a[i] * (6.2/100) * 2);
	}
	return doubles_argmax(c,result);
}

int gas_liters(const double *a, int n, double *b, int m, double x, double *c) {
	int result = 0;

	for(int i = 0; i < n; i++) {
		c[result++] = (x / b[i]) - ((a[i] * (6.2/100)) * 2);
	}
	return doubles_argmax(c,result);
}

void test_fuel() {
	double a[1000];
	double n = doubles_get_until(-1,a);
	double b[1000];
	double m = doubles_get_until(-1,b);
	double c[1000];
	double x = 0;
	while(scanf("%lf", &x) != EOF) {
		int y = gas(a,n,b,m,x,c);
		int z = gas_liters(a,n,b,m,x,c);
		printf("%d %.1f\n", y, c[z]);
	}
}

void unit_test() {
	double a1[7] = {7.2,15.4,16.3,22.5,17.9,35.23,2.4};
	double b1[7] = {1.629,1.573,1.654,1.618,1.622,1.476,1.712};
	double c1[1000];
	assert(gas(a1,7,b1,7,50,c1) == 1);
	assert(gas(a1,7,b1,7,10,c1) == 6);
	assert(gas(a1,7,b1,7,25,c1) == 0);
}

int main() {
	unit_test();
	test_fuel();
	return 0;
}