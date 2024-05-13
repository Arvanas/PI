//A - Soma de todos valores menos posições ímpares

#include <stdio.h>
#include <math.h>
#include <assert.h>

const char *author = "Tomás Arvanas";

int ints_get(int *a) {
    int result = 0;
    int x;
    while(scanf("%d", &x) != EOF)
        a[result++] = x;
    return result;
}

int sum_positions_minus_odd_positions(const int *a, int n) {
    int total = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            total += a[i];
        }
    }
    return total;
}

void unit_test(void) {
    int a1[10] = {2,3,4,8,7,10,2,6,4,3};
    assert(sum_positions_minus_odd_positions(a1,6) == 13);
    assert(sum_positions_minus_odd_positions(a1,3) == 6);
    assert(sum_positions_minus_odd_positions(a1,10) == 19);
    assert(sum_positions_minus_odd_positions(a1,4) == 6);
}

void test(void) {
    int a[1000];
    int n = ints_get(a);
    printf("%d\n", sum_positions_minus_odd_positions(a,n));
}

int main(void) {
    unit_test();
    test();
    return 0;
}