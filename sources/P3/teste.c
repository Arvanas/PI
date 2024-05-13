#include <stdio.h>
#include <math.h>
const char *author="Leonardo Colucas";


//x -> salario 
//y -> hora
//z -> minuto

double salario(double x, int y, int z)
{
	if(y < 13){
		return (1.5 *(y - 9)) * x + (z) * (x/60) * 1.5;
	}
	
	else{
		return (4 * 1.5 * x) + ((y - 14) * 1.75 * x) + (x * 1.75 / 60) * z + 6.5; 
	}
}

double round2(double x, int y, int z)
{
	return round(salario(x,y,z) * 100) / 100;
}

void test(void)
{
	double x;  
    int y;
    int z; 
    while(scanf("%lf%d%d",&x,&y,&z)!=EOF) 
    {
      printf("%.06f\n", round2(x,y,z)); 
    } 
} 

int main(void)
{
	test(); 
	return 0; 
}    