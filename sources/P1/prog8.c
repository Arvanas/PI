//Expoente base 2

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

int power_of_two(int x)
{
	return is_zero(x) ? 1 :twice(power_of_two(pred(x))); // Se x=0 então 1; Se não for, tirar ao x até ser 0 e ir multiplicando	
}

int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d\n", power_of_two(x));
	return 0;
}