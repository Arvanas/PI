//PB - Caracteres e Cadeias

#include <stdio.h>
#include <math.h>
#include <assert.h>

int str_find_sigla_1(const char *s, char x) {
	int result = -1;
	for(int i = 0; s[i] != '\0'; i++) {
		if(s[i] == x && result == -1) {
			result =  i;
		}
	}
	return result;
}

int str_find_sigla_2(const char *t, const char x) {
	int result = -1;
	for(int i = 0; t[i] != '\0'; i++) {
		if(t[i] == x) {
			result = i;
		}
	}
	return result;
}

int alfa2(char *sigla, const char *paises) {
	int result = 0;
	int y = str_find_sigla_1(paises, sigla[0]);
	int z = str_find_sigla_2(paises, sigla[1]);
	if(y < z && y != -1)
		result = 1;
	return result;
}

void test_alfa2(void) {
	char paises[1000];
	char sigla[2];
	scanf("%s", sigla);
	while(scanf("%s", paises) != EOF) {
		if(alfa2(sigla,paises) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

int main(void) {
	test_alfa2();
	return 0;
}