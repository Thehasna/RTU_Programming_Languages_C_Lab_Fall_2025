#include <stdio.h>

long long factorial(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main(void) {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input\n");
    return 1;
    }
    if (n < 0) {
        printf("Error: n must be >= 0\n");
    return 1;
    }
    if (n > 20) {
        printf("Warning: factorial(%d) may overflow 64-bit integer; result may be incorrect.\n", n);
    }
    long long f = factorial(n);
    printf("%d! = %lld\n", n, f);
    return 0;
}
