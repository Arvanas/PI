//Azuleijos
#include <stdio.h>
#include <math.h>

const char *author = "Tomás Arvanas";

int sum(int x, int y)
{
	return y==0 ? x : x + sum(x-1, y-1);
}

int azuis(int l, int a)
{
	return sum(ceil(ceil((double)l/2)-(double)a/2), a-1);
}

int amarelos(int l, int a)
{
	int A = l*a;
	return A - azuis(l, a);
}

void test_sum(void)
{
	int l;
	int a;
	while (scanf("%d%d", &l, &a) != EOF)
	{
		printf("%d %d\n", azuis(l, a), amarelos(l, a));
	}
}

int main(void)
{
	test_sum();
	return 0;
}