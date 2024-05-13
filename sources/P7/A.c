//A - Cereais 

#include <stdio.h>
#include <math.h>
#include <assert.h>

double distancia(double x, double y) {
	double result = ((38.72 - x)*(38.72 - x)) + ((9.14 - y)*(9.14 - y));
	return sqrt(result) * 100;
}

double curvatura(double x, double y) {
	double result;
	if(distancia(x,y) <= 1000)
		result = distancia(x,y) + (distancia(x,y) * 0.12);
	else if(distancia(x,y) > 1000 && distancia(x,y) <= 3000)
		result = distancia(x,y) - (distancia(x,y) * 0.25);
	else
		result = distancia(x,y) + (distancia(x,y) * 0.18);
	return result;
}

void test(void) {
	double x;
	double y;
	while(scanf("%lf%lf", &x, &y) != EOF){
		double z = distancia(x,y);
		double w = curvatura(x,y);
		if(z <= 1000)
			printf("%.3f %s %.3f\n", z,"VT",w);
		else if(z >1000 && z <= 3000)
			printf("%.3f %s %.3f\n", z,"VA",w);
		else
			printf("%.3f %s %.3f\n", z,"VM",w);
		
	}
}

int main(void) {
	test();
	return 0;
}