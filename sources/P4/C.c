#include <stdio.h>

const char *author = "Tomás Arvanas";


double variacao(double x, double y) {
	return x == y ? 0 : (x/y) + 1 + ((0.25 * (y - x)) / 10);
}

double lim(double a, double b) {
	return a > b ? b : a;
}

double dentro_localidade(double x, double y) {
	int a = y - x;

	if(a <= 20) {
		double w = variacao(x, y) * 60;
		return lim(w, 300);
	}
	else if(a >= 21 && a <= 40) {
		double w = variacao(x, y) * 120;
		return lim(w, 600);
	}
	else if(a >= 41 && a <= 60) {
		double w = variacao(x,y) * 300;
		return lim(w, 1500);
	}
	else {
		double w = variacao(x,y) * 500;
		return lim(w, 2500);
	} 
}

double fora_localidade(double x, double y) {
	int a = y - x;

	if(a <= 30) {
		double w = variacao(x, y) * 60;
		return lim(w, 300);
	}
	else if(a >= 31 && a <= 60) {
		double w = variacao(x, y) * 120;
		return lim(w, 600);
	}
	else if(a >= 61 && a <= 80) {
		double w = variacao(x,y) * 300;
		return lim(w, 1500);
	}
	else {
		double w = variacao(x,y) * 500;
		return lim(w, 2500);
	} 
}

void test(void){
	double x;
	double y;
	int z;
	while(scanf("%lf%lf%d", &x, &y, &z) != EOF) {
		if(z == 0) {
			printf("%.2f\n", dentro_localidade(x,y));
		}
		else if(z == 1) {
			printf("%.2f\n", fora_localidade(x,y));
		}
	}
}

int main(void) {
	test();
	return 0;
}