//B - Tesla

#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = "Tomás Arvanas";

double bihourly(double x, double y) {
	double a = (x * 0.26120) + (y * 0.20620);
	double b = a + (a * 0.25) + 18.551; //Taxa 25% e Taxa Potencia
	return b + (b * 0.23); //IVA

}

double simple(double x, double y) {
	double a = (x * 0.23770) + (y * 0.23770);
	double b = a + (a * 0.25) + 15.903; //Taxa 25% e Taxa Potência
	return b + (b * 0.23); //IVA
}

void test(void) {
	double x;
	double y;
	while(scanf("%lf%lf", &x, &y) != EOF) {
		double z = simple(x,y);
		double w = bihourly(x,y);
		printf("%.2f %.2f\n", z, w);
	}
}

int main(void) {
	test();
	return 0;
}