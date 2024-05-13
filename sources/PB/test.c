#include <stdio.h>
#include <assert.h>

int str_find (const char *s, char x)
{
	int result = -1;
	for(int i = 0;s[i] != '\0'; i++)
	{
		if(s[i] == x && result == -1)
			result = i;
	}
	return result;
}

int alfa3(const char *sigla, const char *paises)
{
	int y = str_find(paises, sigla[0]);
	if(y != -1) {
		paises += y + 1;
		y = str_find(paises, sigla[1]);
		y = str_find(paises, sigla[2]);
	}
	return y;

	int w = y;
	if(w >= 0)
		w = 1;
	else
		w = 0;
	return w;
}

void test_alfa3(void) {
	char sigla[1000];
	scanf("%s", sigla);
	char paises[1000];
	int resultado[2000];
	int i = 0;
	while(scanf("%s", paises) != EOF) {
		resultado[i] = alfa3(sigla, paises);
		i++;
	}
	int n = 0;
	while(n < i) {
		if(resultado[n] == 1)
			printf("YES\n");
		else if(resultado[n] == 0)
			printf("NO\n");
		n++;
	}
}

int main(void) {
	test_alfa3();
	return 0;
}