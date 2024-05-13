//Menor ou Igual

#include <stdio.h>

const char *author = "Tomás Arvanas";

int succ(int x);
int pred(int x);
int is_zero(int x);
int is_pos(int x);

int diff(int x, int y)
{
	return is_zero(y) ? x : diff(pred(x), pred(y));
}

int lessequal(int x, int y)
{
	return is_pos(diff(y, x)); // Se a diferença de y e x for "+" e "0" então 1, se for "-" então 0
}

int main(void)
{
	int x;
	int y;
	scanf("%d%d", &x, &y);
	int z = lessequal(x, y);
	printf("%d\n", z);
	return 0;
}


