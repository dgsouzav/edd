#include <stdio.h>

int main() {
    int n, p, i;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    printf("Digite o valor de P: ");
    scanf("%d", &p);
    for (i = 1; i <= p; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
    return 0;
}