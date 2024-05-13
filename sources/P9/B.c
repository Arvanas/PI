//B - Todos iguais

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


int ints_all_equal(const int *a, int n) {
    int result = 0;
    for(int i = 0; i < n; i++) {
        if(a[0] == a[i]) {
            result++;
        }
    }
    if(result == n){
        return 1;
    }
    else{
        return 0;
    }
}

void unit_test(void) {
    int a1[10] = {1,1,1,1,1,1,1,2,1,1};
    assert(ints_all_equal(a1,3) == 1);
    assert(ints_all_equal(a1,6) == 1);
    assert(ints_all_equal(a1,8) == 0);
    assert(ints_all_equal(a1,10) == 0);
    assert(ints_all_equal(a1,0) == 1);
}

void test(void) {
    int a[1000];
    int n = ints_get(a);
    printf("%d\n", ints_all_equal(a,n));
}

int main(void){
    unit_test();
    test();
    return 0;
}