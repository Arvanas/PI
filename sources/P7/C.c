//C - Programação Imperial

#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = "Tomás Arvanas";

int ints_get(int *contest) {
	int result = 0;
	int x;
	while(scanf("%d", &x) != EOF)
		contest[result++] = x;
	return result;
}

int bonus(const int *contest, int n) {
	int pontos_bonus = 0;
	for(int i = 0; i < n/2; i++) {
		int x = i + (n/2);
		if(2 * contest[x] >= contest[i]) {
			pontos_bonus += 1;
		}
		else {
			pontos_bonus += 0;
		}
	}
	return pontos_bonus;
}

int points(const int *contest, int n) {
	double points = 0;
	for(int i = n/2; i < n; i++)
		points += contest[i];
	return points * 3 + bonus(contest,n);
}

void test(void) {
	int contest[1000];
	int a = ints_get(contest);
	printf("%d\n", points(contest,a));
}

int main(void) {
	test();
	return 0;
}