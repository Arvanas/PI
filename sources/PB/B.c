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

int str_find2(const char *s, char x)
{
	int result = -1;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == x)
			result = i;
	}
	return result;
}

int alpha3_1(const char *x, const char *s)
{
	int z = str_find(s,*x);
	if(z != -1) {
		s += z + 1;
		z = str_find(s,x[1]);
		z = str_find(s,x[2]);	
	}
	/*
	if (z != -1) {
		s += z + 1;
		z = str_find(s,x[2]);
	}
	*/
	return z;
}

int alpha3 (const char *x, const char *s)
{
	int w = alpha3_1(x,s);
	if(w >= 0)
		w = 1;
	else 
		w = 0;
	return w;
}

void teste_alpha3 (void)
{
	char s[1000];
	char x[1000];
	scanf("%s", x);
	while(scanf("%s", s) != EOF)
	{
		int result = alpha3(x,s);
		if(result == 1)
			printf("YES\n");
		else 
			printf("NO\n");		
	}
}

int main(void) {
	teste_alpha3();
	return 0;
}