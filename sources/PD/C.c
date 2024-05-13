// C - String

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

const char *author = "Tomás Arvanas";

void print_string(const char *x, int n) {
	if(n > 0) {
		for(int i = 0; i < n; i++)
			printf("%c", x[i]);
	}
	printf("\n");
}

int pass(int i) {
	return i < 10 ? i : i % 10; //Return do indice
}

int word(char *x, const char *s) {
	int result = 0;
	for(int i = 0; s[i] != '\0'; i++) {
		if(result == 0) {
			result++;
			x[result - 1] = s[0];
		}
		else if(s[i] == '_') {
			result = result + 2;
			x[result - 2] = '0' + pass(i);
			x[result - 1] = s[i+1];
		}
	}
	return result;
}

void test_password(void) {
	char s[1000];
    char x[1000];
    while (scanf("%s", s) != EOF) {
        print_string(x, word(x, s));
    }
}
/*
void unit_test() {
	char s[8] = {'M','o','n','e','y','\0'};
	char x[1000];
	assert(word(x,s) == 1 && x[0] == 'M');

	char s1[12] = {'a','g','u','a','_','m','o','l','e','\0'};
	char x1[1000];
	assert(word(x1,s1) == 3 && x1[0] == 'a' && x1[1] == '4' && x1[2] == 'm');

	char s2[12] = {'g','o','s','t','o','_','p','i','\0'};
	char x2[1000];
	assert(word(x2,s2) == 3 && x2[0] == 'g' && x2[1] == '5' && x2[2] == 'p');
}
*/
int main() {
	//unit_test();
	test_password();
	return 0;
}