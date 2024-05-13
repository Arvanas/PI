//Máximo

#include <stdio.h>

const char *author = "Tomás Arvanas";

int succ(int x);
int pred(int x);
int is_zero(int x);
int is_pos(int x);

int difference(int x, int y)
{
	return is_zero(y) ? x : difference(pred(x), pred(y));
}

int max(int x, int y)
{
	return is_pos(difference(x, y)) ? x : y; // Verificar se a diferença é negativa. Se for "+" ou "0", então x se for "-" é y
}

int main(void)
{
	int x;
	int y;
	scanf("%d%d", &x, &y);
	int z = max(x, y);
	printf("%d\n", z);
	return 0;
}