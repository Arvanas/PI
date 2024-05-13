// A - Conversor de Cripto Moedas

#include <stdio.h>

const char *author = "Tomás Arvanas";

double bitcoin(int x, double y) {
    if(x == 1) {
        return y * 1449.87; //ETH
    }
    else if(x == 2) {
        return y * 146.78; //XMR
    }
    else if(x == 3) {
        return y * 55.86; //LTC
    }
    return 0;
}

double convert_us(int x, double y) {
    return bitcoin(x,y) * 1.02;
}

void test(void) {
    int x;
    double y;
    while(scanf("%d%lf", &x, &y) != EOF) {
        double z = bitcoin(x, y);
        double w = convert_us(x, y);
        printf("%.2f\n", z);
        printf("%.3f\n", w);
    }
}

int main(void) {
    test();
    return 0;
}