//Dobro

#include <stdio.h>

const char *author = "Tomás Arvanas";

int succ(int x);
int pred(int x);
int is_zero(int x);
int is_pos(int x);

int sum(int x, int y)
{
	return is_zero(y) ? x : sum(succ(x), pred(y));
}

int twice(int x)
{
	return sum(x, x);
}

int main(void)
{
	int x;
	scanf("%d", &x);
	int z = twice(x);
	printf("%d\n", z);
	return 0;
}
