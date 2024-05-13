//Soma dos inversos quadrados
#include <stdio.h>
#include <math.h>

const char *author = "Tomás Arvanas";

double sum_powers_from(double x, double y, int n)
{
	return n == 0 ? 0 : pow(x, y) + sum_powers_from(x+1,y,n-1);
}


double sum_inversessquares(int n)
{
	double x = 1;
	double y = -2;
	return sum_powers_from(x,y,n);
}


void test(void)
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		double z = sum_inversessquares(n);
		printf("%lf\n", z);
	}
}

int main(void)
{
	test();
	return 0;
}