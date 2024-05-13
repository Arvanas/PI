// Soma dos N números inteiros positivos . P2

#include <stdio.h>

const char *author = "Tomás Arvanas";

int sum_positive_integers(int n)
{
	return n==0 ? 0 : n + sum_positive_integers(n-1);
}

void test_sum_positive_integers(void)
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int x = sum_positive_integers(n);
		printf("%d\n", x);
	}
}

int main(void)
{
	test_sum_positive_integers();
	return 0;
}