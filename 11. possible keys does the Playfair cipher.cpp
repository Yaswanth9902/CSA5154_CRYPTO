#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    unsigned long long total_keys;
    total_keys = factorial(25);
    
    printf("Total possible keys (approximate power of 2): 2^%d\n", (int)(log2(total_keys)));
    
    return 0;
}
