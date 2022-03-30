#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;

    printf("digite o valor de n: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        for(j = n - 1; j >= 1; j--)
            printf(" ");
        for(j = 1; j <= i; j++) 
            printf("*");
        printf(" ");
        for(j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}