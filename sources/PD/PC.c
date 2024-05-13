//PC - Festa de Programação

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include "our_ints.h"
#include "our_doubles.h"

const char *author = "Tomás Arvanas";

///////////////// A - MUndial de Futebol ////////////////////////

void doubles_exchange(double *a, int x, int y) {
	double m = a[x];
	a[x] = a[y];
	a[y] = m;
}

void double_sort_last(double *a, int n) {
	while(n >= 2 && a[n-2] > a[n-1]) {
		double_exchange(a, n - 2, n - 1);
	}
}

void double_sort(double *a, int n) {
	for(int = 2; i <= n; i++) {
		double_sort_last(a,i);
	}
}

double doubles_insert(double *a, int n, double x) {
	int result = n;
	a[result++] = x;
	double_sort_last(a,result);
	return result;
}

double avg_km(double const *a, int n) {
	double result;
	for(int i = 0; i < n; i = i + 3) {
		result += a[i];
	}
	return result /30;
}

double mode_km(double const *a, int n) {
	double moda = 0;
    double aux = 0;
    int cont2 = -1;
    double c[1000];

    for (int i = 0; i < n; i = i + 3)
    {
        cont2++;
        c[cont2] = a[i];
    }

    for (int i = 0; i < cont2; i++)
    {

        if (doubles_count(c, cont2 + 1, c[i]) > aux)
        {
            aux = doubles_count(c, cont2 + 1, c[i]);
            moda = c[i];
        }
    }

    return moda;
}

double med_km(double const *a, int n)
{

    double c[1000];
    int cont2 = -1;
    double mediana = 0;

    for (int i = 0; i < n; i = i + 3)
    {
        cont2++;
        c[cont2] = a[i];
    }

    double_sort(c, cont2 + 1);

    mediana = (c[(cont2) / 2] + c[(((cont2) / 2) + 1)]) / 2;

    return mediana;
}

double total_weight(double const *a, int n)
{
    double peso;
    int cont2 = -1;

    for (int i = 1; i < n; i = i + 3)
    {
        cont2++;
        peso += a[i] - a[i + 1];
    }

    return peso;
}

void test_world_cup(void)
{

    double a[1000];
    double n = doubles_get(a);
    printf("%.2f %.2f %.2f %.2f\n", avg_km(a, n), mode_km(a, n), med_km(a, n), total_weight(a, n));
}

////////////////// B - Combustivel //////////////////////////////

int gas(const double *a, int n, double *b, int m, double x, double *c) {
	int result = 0;

	for(int i = 0; i < n; i++) {
		c[result++] = (x / b[i]) - (a[i] * (6.2/100) * 2);
	}
	return doubles_argmax(c,result);
}

int gas_liters(const double *a, int n, double *b, int m, double x, double *c) {
	int result = 0;

	for(int i = 0; i < n; i++) {
		c[result++] = (x / b[i]) - ((a[i] * (6.2/100)) * 2);
	}
	return doubles_argmax(c,result);
}

void test_fuel() {
	double a[1000];
	double n = doubles_get_until(-1,a);
	double b[1000];
	double m = doubles_get_until(-1,b);
	double c[1000];
	double x = 0;
	while(scanf("%lf", &x) != EOF) {
		int y = gas(a,n,b,m,x,c);
		int z = gas_liters(a,n,b,m,x,c);
		printf("%d %.1f\n", y, c[z]);
	}
}

///////////////////////// C - Password //////////////////////////////

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
			//x[result - 1] = s[i+1];
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

//////////////// Unit Test ////////////////////////////

void unit_test_fuel() {
	double a1[7] = {7.2,15.4,16.3,22.5,17.9,35.23,2.4};
	double b1[7] = {1.629,1.573,1.654,1.618,1.622,1.476,1.712};
	double c1[1000];
	assert(gas(a1,7,b1,7,50,c1) == 1);
	assert(gas(a1,7,b1,7,10,c1) == 6);
	assert(gas(a1,7,b1,7,25,c1) == 0);
}

void unit_test_password() {
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


void unit_test() {
	unit_test_fuel();
	unit_test_password();
}


int main(int argc, char **argv) {
	unit_test();
	int x = 'A';
	if(argc > 1)
		x = *argv[1];
	if (x == 'A')
		test_worldcup();
	else if (x == 'B')
		test_fuel();
	else if (x == 'C')
		test_password();
	else
		printf("%s: Invalid option.\n", argv[1]);
	return 0;
}