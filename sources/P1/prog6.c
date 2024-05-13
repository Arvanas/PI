//Metade

#include <stdio.h>

const char *author = "Tomás Arvanas";

int succ(int x);
int pred(int x);
int is_pos(int x);
int is_zero(int x);

int half(int x)
{
	return is_zero(x) ? 0 : is_zero(pred(x)) ? 0 : succ(half(pred(pred(x))));
	//       x==0            x==1 -> x-1==0           x-2
}

int main (void)
{
	int x;
	scanf("%d", &x);
	int y = half(x);
	printf("%d\n", y);
	return 0;
}