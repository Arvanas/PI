//Compras On-line - P4
#include <stdio.h>
#include <math.h>

const char *author = "Tomás Arvanas";


double total_no_prom(double x, int y, int z) {
	return (y * (x - (x * 0.10) - (x * 0.15))) + (z * (x - (x * 0.15)));
}

double second_prom(int y, int z) {
	int tshirt = (y + z) / 3;
	return tshirt;
}

double desconto(double x, int y, int z) {
	int a = y - second_prom(y,z);
	int b = z - a;
	double total;
	if(second_prom(y,z) < 1) {
		total = total_no_prom(x,y,z); 
	} 
	else if(second_prom(y,z) < y) {
		total = total_no_prom(x, y - second_prom(y,z), z);
	}
	else {
		total = total_no_prom(x, 0, b);
	}
	return total;
}

double unidade(double x, int y, int z) {
	return desconto(x,y,z) / (y+z);
}

double arredondamento(double x, int y, int z) {
	return round(unidade(x,y,z) * 100) / 100;
}


void test() {
	double x;
	int y;
	int z;
	while(scanf("%lf%d%d", &x, &y, &z) != EOF) {
		double a = arredondamento(x,y,z);
		printf("%.6f\n", a);

	}
}

int main() {
	test();
	return 0;
}