// B - Sequência Semanal

#include <stdio.h>

const char *author = "Tomás Arvanas";

int dias(int y) {
    return y <= 7 ? y : y % 7 == 0 ? 7 : y % 7;
}

int mesas(int y) {
    return y == 1 ? 6 : 4 + mesas(y - 1);
}



void test(void) {
    int x;
    int y;
    while(scanf("%d%d", &x, &y) != EOF) {
        int result;
        if(x==1) {
            result = dias(y);
            printf("%d\n", result);
        }
        else if(x==2){
            result = mesas(y);
            printf("%d\n", result);
        }
    }
}

int main(void) {
    test();
    return 0;
}
