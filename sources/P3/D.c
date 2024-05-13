// D - Horas extraordinárias

#include <stdio.h>
#include <math.h>

const char *author = "Tomás Arvanas";

double pay(double x, int y, int z) {
	double result;
	if(y <= 13) {
		result = (1.5 * x * (y - 9))  + (z * (x/60) * 1.5);
	}
	else {
		result = (4 * 1.5 * x) + (1.75 * x * (y-14)) + (z * (x/60) * 1.75) + 6.5;
	}
	return result;
}

double round2(double x, int y, int z) {
	return round(pay(x,y,z) * 100) / 100;
}

void test(void) {
	double x;
	int y;
	int z;
	while(scanf("%lf%d%d", &x, &y, &z) != EOF) {
        double a = round2(x, y, z);
        printf("%.6f\n", a);
    }
}


int main(void) {
	test();
	return 0;
}