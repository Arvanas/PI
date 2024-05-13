//Progressões aritmétricas

#include <stdio.h>

const char *author = "Tomás Arvanas";

int sum_positives_integers(int n)
{
	return n == 0 ? n : n + sum_positives_integers(n-1);
}

int sum_multiples(int r, int n)
{
	return n == 0 ? 0 : r * sum_positives_integers(n-1);
}

int sum_progression(int x0, int r, int n)
{
	return sum_multiples(r,n) + x0*n;
}

void test_sum_multiples(void)
{
	int x0;
	int r;
	int n;
	while(scanf("%d%d%d", &x0, &r, &n) != EOF)
	{
		int z = sum_progression(x0, r, n);
		printf("%d\n", z);
	}
}

int main(void) {
	test_sum_multiples();
	return 0;
}