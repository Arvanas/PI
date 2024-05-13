//PB - Caracteres e Cadeias

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

const char *author = "Tomás Arvanas";

//////////////////////////Alfa 2/////////////////////////

int str_find(const char *s, char x) {
	int result = -1;
	for(int i = 0; s[i] != '\0'; i++) {
		if(s[i] == x && result == -1) {
			result =  i;
		}
	}
	return result;
}

int str_find2(const char *t, char x) {
	int result = -1;
	for(int i = 0; t[i] != '\0'; i++) {
		if(t[i] == x) {
			result =  i;
		}
	}
	return result;
}

int alfa2(char *sigla, const char *paises) {
	int result = 0;
	int y = str_find(paises, sigla[0]);
	int z = str_find2(paises, sigla[1]);
	if(y < z && y != -1)
		result = 1;
	return result; 
}

void test_alfa2(void) {
	char paises[1000];
	char sigla[2];
	scanf("%s", sigla);
	int resultado[1000];
	int i = 0;
	while(scanf("%s", paises) != EOF) {
		resultado[i] = alfa2(sigla, paises);
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


////////////////////////////Alfa 3///////////////////////

int alfa3(const char *sigla, const char *paises) {
	int y = str_find(paises, *sigla);
	if(y != -1) {
		paises += y + 1;
		y = str_find(paises, sigla[1]);
	}
	if(y != -1) {
		paises += y + 1;
		y = str_find(paises, sigla[2]);
	}
	return y;
}

int alfa3_res(const char *sigla, const char *paises) {
	int w = alfa3(sigla,paises);
	if(w >= 0)
		w = 1;
	else 
		w = 0;
	return w;
}

void test_alfa3(void) {
	char sigla[3];
	scanf("%s", sigla);
	char paises[1000];
	int resultado[2000];
	int i = 0;
	while(scanf("%s", paises) != EOF) {
		resultado[i] = alfa3_res(sigla, paises);
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

///////////////////Subsequências////////////////////////
int null(const char *sigla, char *palavra) {
	int result = 0;
	for(int i = 1; sigla[i] != '\0'; i++) {
		if(sigla[i] == ' ')
			result = 1;
	}
	return result;
}

int subsequencia(const char *sigla, char *palavra) {
	int result = str_find(palavra, *sigla);
	for(int i = 1; sigla[i] != '\0'; i++) {
		if(result != -1) {
			palavra += result + 1;
			result = str_find(palavra, sigla[i]);
		}
	}
	return result;
}

int sub(const char *sigla, char *palavra) {
	int result = 0;
	if(subsequencia(sigla,palavra) >= 0)
		result = 1;
	else if(null(sigla,palavra) == 1)
		result = 1;
	else
		result = 0;
	return result;
}

void test_sub(void)
{
	char sigla[1000];
	char palavra[1000];
	int res[2000];
	int i=0;
	while (scanf("%s%s", sigla, palavra) != EOF) {
		res[i]=sub(sigla, palavra);
		i++;
	}
	int n=0;
	while (n<i) {
		if (res[n]==1)
			printf("YES\n");
		else if (res[n]==0)
			printf("NO\n");	
		n++;
	}
}

//////////////////////Telegramas/////////////////////////

int str_count(const char* s)
{
	int result = 0;
	for (int i = 0; s[i] != '\0'; i++)
			result++;
	return result;
}

void tele(const char* palavra, char* palavra_nova, char* res)
{
	int w = str_count(palavra);
	int t=0;
	for(int i = 0; i < w; i++)
	{
		
		if (palavra[i]!='_')
		{
			palavra_nova[t]=palavra[i];
			palavra_nova[t+1]='\n';
			t++;
		}
	}
	strcat(res,palavra_nova);
}

void test_tele(void)
{
	char palavra[1000];
	
	char res[1000]="";
	int j=0;
	while (scanf("%s", palavra) != EOF)
	{
		char palavra_nova[1000]="";
		tele(palavra, palavra_nova, res);
		j++;
	}
	printf("%s", res);	
}


///////////////////////UNIT TEST/////////////////////////

void unit_test() {
	assert(str_find("abcdedfghi", 'a') == 0);
	assert(str_find("abcdedfghi", 'g') == 7);
	assert(str_find("abcdedfghi", 'i') == 9);
	assert(str_find2("abcdedfghi", 'p') == -1);
	assert(str_find2("", 'z') == -1);

	assert(alfa2("pt", "portugal") == 1);
	assert(alfa2("fr", "franca") == 1);
	assert(alfa2("lk", "sri lanka") == 1);
	assert(alfa2("de", "alemanha") == 0);
	assert(alfa2("zb", "brazil") == 0);

	assert(alfa3_res("prt", "portugal") == 1);
	assert(alfa3_res("frn", "franca") == 1);
	assert(alfa3_res("slk", "sri lanka") == 1);
	assert(alfa3_res("dem", "alemanha") == 0);
	assert(alfa3_res("zbl", "brazil") == 0);	
}

/////////////////////////MAIN///////////////////////////

int main(int argc, char **argv) {
	unit_test();
	int x = 'A';
	if(argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_alfa2();
	else if (x == 'B')
		test_alfa3();
	else if (x == 'C')
		test_sub();
	else if (x == 'D')
		test_tele();
	else
		printf("%s: Invalid option.\n", argv[1]);
	return 0;
}