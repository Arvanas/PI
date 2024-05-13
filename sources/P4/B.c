//Conversão - P4

#include <stdio.h>
#include <math.h>

const char *author = "Tomás Arvanas";

int arredondamento(int x, int y) {
	return x < 100 ? x * y : arredondamento(x/10, y*10);
}

void test(void) {
	int x;
	int y = 1;
	while (scanf("%d", &x) != EOF) {
		printf("%d\n", arredondamento(x,y));
	}
}

int main(void) {
	test();
	return 0;
}